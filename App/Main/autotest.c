/**
 * --------------------------------------------------------------------
 * @file    autotest.c
 * @author  Austral Electronics
 * @version V1.0
 * @date    14/04/2022
 * @brief   Thunderball H7 Autotest functions
 * -------------------------------------------------------------------- */

#include "common.h"

uint8_t Rx_data[10];  //  creating a buffer of 10 bytes

// USE :open a console on COM1 at 115200 bauds with putty to interact with the stdio flow of this autotest
void AutotestFram() {
    printf("\n\rThunderball H7 - Very simple autotest - !!! Not compatible with PCB <=REV03 !!!!\n\r");

    FramInit(hspi1, SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    // Test FRAM with 4 bytes
    printf("FRAM Write32 0xDEADBEEF.......");
    uint32_t rx=0xDEADBEEF;
    FramWrite32(0x10, rx);
    rx=0;   
    FramRead(0x10, &rx, sizeof(rx));
    if (rx==0xDEADBEEF) printf("OK\n\r");
    else printf("!!!! Error %lx!!!!\n\r",rx);

    // Test FRAM with uint32_t
    printf("FRAM uint32_t 0x4321CAFE......");
    rx=0x4321CAFE;
    FramWrite(0x07F0, &rx, sizeof(rx));
    rx=0;   
    FramRead(0x07F0, &rx, sizeof(rx));
    if (rx==0x4321CAFE) printf("OK\n\r");
    else printf("!!!! Error %lx!!!!\n\r",rx);

    // Test FRAM with float
    float f=3.14159;
    printf("FRAM float 3.14159............");
    FramWrite(0x07F0, &f, sizeof(f));
    f=0.0;
    FramRead(0x07F0, &f, sizeof(f));
    if (fabs(f-3.14159)<1E-6) printf("OK\n\r");
    else printf("!!!! Error !!!!\n\r");

    //HAL_Delay(100);
    printf("\n\rIf you have FRAM errors, verify the PCB revision, the main branch is for REV04 PCB\n\r");

    printf("\n\rPress 'space' in the console to test serials, 'b' to jump to the bootloader\n\r");
}

void AutotestPooling(void) {

    // AUTOTEST : COM5 (huart2) RS232_RX test
    // USE : Open a second putty console at 115Kb and connect it to COM2..5 with wiring for RS232_RX, send somes characters, they will be displayed on the COM1 console
    if (HAL_UART_Receive(&huart2, Rx_data, 1, 0) == HAL_OK) printf("COM5 : %c\n\r",Rx_data[0]);

    // AUTOTEST : COM4 (huart5) RS232_RX test 
    if (HAL_UART_Receive(&huart5, Rx_data, 1, 0) == HAL_OK) printf("COM4 : %c\n\r",Rx_data[0]);

    // AUTOTEST : COM3 (huart4) RS232_RX test
    if (HAL_UART_Receive(&huart4, Rx_data, 1, 0) == HAL_OK) printf("COM3 : %c\n\r",Rx_data[0]);

    // AUTOTEST : COM2 (huart3) RS232_RX test
    if (HAL_UART_Receive(&huart3, Rx_data, 1, 0) == HAL_OK) printf("COM2 : %c\n\r",Rx_data[0]);

    // AUTOTEST : COM1 (huart7) Autotest Console (press space or 'b' in the COM1 putty console)
    if (HAL_UART_Receive(&huart7, Rx_data, 1, 0) == HAL_OK) {
        // AUTOTEST : Call to the Bootloader Test
        // USE : press 'b' in the COM1 console.
        if (Rx_data[0]=='b') {
            printf("\n\r!!!! Launch the Bootloader : Use STM32CubeProgrammer and a USB-C cable to bootload a .bin firmware !!!");
            JumpToBootloader();             // Bootload
        }

        if (Rx_data[0]==' ') {
            // AUTOTEST : RTC Test
            // USE : the time should change each time you press the space bar in the COM1 console.
            RTC_TimeTypeDef sTime = {0};
            if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN)== HAL_OK) {         // Display time
                RTC_DateTypeDef sDate = {0};
                HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); // Unlock RTC
                printf("\n\rTime: %lu:%lu:%lu\n\r",(uint32_t) (sTime.Hours),(uint32_t) (sTime.Minutes),(uint32_t) (sTime.Seconds));
            } else printf("RTC error\n\r");

            // AUTOTEST : RTS and Backlight Test
            // USE : Strap RTS to CTS on COM1, CTS and the Backlight have to change state every time you press the space bar in the COM1 console.
            HAL_GPIO_TogglePin(UART7_RTS_GPIO_Port, UART7_RTS_Pin); // Toggle RTS
            HAL_GPIO_TogglePin(CMD_LED_GPIO_Port, CMD_LED_Pin);     // Toggle backlight
            printf("Toggle COM1_RTS & Backlight\n\r");
            if (HAL_GPIO_ReadPin(UART7_CTS_GPIO_Port, UART7_CTS_Pin))   printf("COM1 CTS = 1\n\r");
            else                                                        printf("COM1 CTS = 0\n\r");

            // AUTOTEST : TX on COM2 (huart3) , RX on COM3 (huart4)
            // USE : Wire a RS422 point-to-point cable (!!! with terminations and bias resistors !!!) to send data from TX+/TX- on one COM to RX+/RX- on another.
            //       Connect the TX side of this cable to COM2 and the Rx side to COM3, Press the space bar on the COM1 console, you must see 'TX on COM2, RX on COM3 OK'
            //       Move this cable and press the space bar to test the following COM ports
            char *msg = "2";
            HAL_UART_Receive(&huart4, Rx_data, 10, 0);
            HAL_UART_Transmit(&huart3, (uint8_t*)msg, strlen(msg), 0xFFFF);
	        if (HAL_UART_Receive(&huart4, Rx_data, 1, 20) == HAL_OK) {
		        if (Rx_data[0]=='2') printf("TX on COM2, RX on COM3 OK\n\r");
                else  {
                    __HAL_UART_CLEAR_OREFLAG(&huart4);
                    printf("TX on COM2, RX on COM3 !!!!Error !!!!\n\r");
                }
            } else printf("TX on COM2, RX on COM3 !!!!Error !!!!\n\r");

            // AUTOTEST : TX on COM3 (huart4) , RX on COM4 (huart5)
            msg = "3";
            HAL_UART_Receive(&huart5, Rx_data, 10, 0);
            HAL_UART_Transmit(&huart4, (uint8_t*)msg, strlen(msg), 0xFFFF);
	        if (HAL_UART_Receive(&huart5, Rx_data, 1, 20) == HAL_OK) {
		        if (Rx_data[0]=='3') printf("TX on COM3, RX on COM4 OK\n\r");
                else  {
                    __HAL_UART_CLEAR_OREFLAG(&huart5);
                    printf("TX on COM3, RX on COM4 !!!!Error !!!!\n\r");
                }
            } else printf("TX on COM3, RX on COM4 !!!!Error !!!!\n\r");

            // AUTOTEST : TX on COM4 (huart5) , RX on COM2 (huart3)
             msg = "4";
            HAL_UART_Receive(&huart3, Rx_data, 10, 0);
             HAL_UART_Transmit(&huart5, (uint8_t*)msg, strlen(msg), 0xFFFF);
            if (HAL_UART_Receive(&huart3, Rx_data, 1, 20) == HAL_OK) {
                 if (Rx_data[0]=='4') printf("TX on COM4, RX on COM2 OK\n\r");
                    else  {
                        __HAL_UART_CLEAR_OREFLAG(&huart3);
                        printf("TX on COM4, RX on COM2 !!!!Error !!!!\n\r");
                    }
            } else printf("TX on COM4, RX on COM2 !!!!Error !!!!\n\r");

            // AUTOTEST : Loop on COM5 (huart2)
            msg = "5";
            HAL_UART_Receive(&huart2, Rx_data, 10, 0);
            HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 0xFFFF);
	        if (HAL_UART_Receive(&huart2, Rx_data, 1, 20) == HAL_OK) {
		        if (Rx_data[0]=='5') printf("Loop on COM5 OK\n\r");
                else  {
                    __HAL_UART_CLEAR_OREFLAG(&huart2);
                    printf("Loop on COM5 !!!!Error !!!!\n\r");
                }
            } else printf("Loop on COM5 !!!!Error !!!!\n\r");

            // AUTOTEST : Send a CANbus sentence on CAN1
            TransmitCAN_Test(&hfdcan1);
            // AUTOTEST : Send a CANbus sentence on CAN2
            TransmitCAN_Test(&hfdcan2);
        }
    }
}