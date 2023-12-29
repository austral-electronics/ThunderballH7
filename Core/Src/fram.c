/**
 ******************************************************************************
 * @file    fram.h
 * @author  AUSTRAL Electronic
 * @version V1.0
 * @date    2022
 * @brief   fram.c definitions
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2022 AUSTRAL Electronics </center></h2>
 */
#include "fram.h"

/** @defgroup FRAM_Constants
 * @{
 */

// #define USE_FASTREAD  1            // FM25V02

#define WRITE 0x02;
#define READ 0x03;
#define FASTREAD 0x0B;
#define DUMMY 0xAA;

/** @defgroup FRAM_Variables
 * @{
 */
uint8_t WRITEENABLE = 0x06;
uint8_t STATUSREGISTER = 0x05;
uint8_t DEVICEID = 0x9F;
uint8_t RDSR = 0x05;
uint8_t WRSR = 0x01;
uint8_t WRDI = 0x04;
uint16_t csPin;
GPIO_TypeDef *csPort;
SPI_HandleTypeDef hspi;

/**
 * @brief	Init a SPI FRAM
 * @note	Optimized for: FM25V02
 * @param  _hspi		NVM address (in bytes)
 * @param  _csPin		pointer to data to write
 * @param  _csPort		Bytes number to write
 * @retval None
 */
void aFramInit(SPI_HandleTypeDef _hspi, GPIO_TypeDef *_csPort, uint16_t _csPin) {
    csPin = _csPin;
    csPort = _csPort;
    hspi = _hspi;
}

/**
 * @brief	Write data to FRAM
 * @note	Optimized for: FM25V02
 * @param  address		NVM address (in bytes)
 * @param  pdata		pointer to data to write
 * @param  nbbytes		Bytes number to write
 * @retval None
 */
void aFramWrite(uint16_t address, void *pdata, uint32_t nbbytes) {

    uint8_t *p = pdata;
    uint8_t txBuffer[3] = {0};
    txBuffer[0] = WRITE;
    txBuffer[1] = (uint8_t)((address & 0xFF00) >> 8);
    txBuffer[2] = (uint8_t)(address & 0x00FF);
    // DBG("-I- FRAM - Byte write: 0x%2X 0x%2X 0x%2X 0x%2X at 0x%4X\r\n",p[3],p[2],p[1],p[0], address);

    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET);    /* CS = 0 */
    HAL_SPI_Transmit(&hspi, &WRITEENABLE, 1, 1000); /* Send SPI a write enable */
    WAIT_TX_BUF_EMPTY(hspi);                        /* Wait for SPI Tx buffer empty */
    HAL_GPIO_WritePin(csPort, csPin, GPIO_PIN_SET); /* CS=1 */

    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET);                   /* CS = 0 */
    HAL_SPI_Transmit(&hspi, &txBuffer[0], sizeof(txBuffer), 1000); /* Send SPI a write data opcode */
    WAIT_TX_BUF_EMPTY(hspi);                                       /* Wait for SPI Tx buffer empty */

    while (nbbytes--) {                        /* Send data byte per byte */
        WAIT_TX_BUF_EMPTY(hspi);               /* Wait for SPI Tx buffer empty */
        HAL_SPI_Transmit(&hspi, p++, 1, 1000); /* Send SPI data */
    }
    WAIT_TX_BUF_EMPTY(hspi);                   /* Wait for SPI Tx buffer empty */
    HAL_GPIO_WritePin(csPort, csPin, PIN_SET); /* CS=1 */
}

/**
 * @brief	Write a 32 bits word to FRAM
 * @note	Optimized for: FM25V02
 * @param  address		NVM address (in bytes)
 * @param  data			data to write
 * @retval None
 */
void aFramWrite32(uint16_t address, uint32_t data) {

    uint8_t txBuffer[7] = {0};
    txBuffer[0] = WRITE;
    txBuffer[1] = (uint8_t)((address & 0xFF00) >> 8);
    txBuffer[2] = (uint8_t)(address & 0x00FF);
/*
    txBuffer[3] = (uint8_t)((data & 0xFF000000) >> 24);
    txBuffer[4] = (uint8_t)((data & 0x00FF0000) >> 16);
    txBuffer[5] = (uint8_t)((data & 0x0000FF00) >> 8);
    txBuffer[6] = (uint8_t)(data & 0x000000FF);
*/
    txBuffer[3] = (uint8_t)(data & 0x000000FF);
    txBuffer[4] = (uint8_t)((data & 0x0000FF00) >> 8);
    txBuffer[5] = (uint8_t)((data & 0x00FF0000) >> 16);
    txBuffer[6] = (uint8_t)((data & 0xFF000000) >> 24);



    // DBG("-I- FRAM - Byte write: 0x%2X 0x%2X 0x%2X 0x%2X at 0x%5X\r\n",txBuffer[6],txBuffer[5],txBuffer[4],txBuffer[3], address);

    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET);    /* CS = 0 */
    HAL_SPI_Transmit(&hspi, &WRITEENABLE, 1, 1000); /* Send SPI a write enable */
    WAIT_TX_BUF_EMPTY(hspi);                        /* Wait for SPI Tx buffer empty */
    HAL_GPIO_WritePin(csPort, csPin, GPIO_PIN_SET); /* CS=1 */

    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET);                   /* CS = 0 */
    HAL_SPI_Transmit(&hspi, &txBuffer[0], sizeof(txBuffer), 1000); /* Send SPI a write data opcode */

    WAIT_TX_BUF_EMPTY(hspi);                   /* Wait for SPI Tx buffer empty */
    HAL_GPIO_WritePin(csPort, csPin, PIN_SET); /* CS=1 */
}

/**
 * @brief	Read a bytes in FRAM
 * @note	Optimized for: FM25V02
 * @param  address		NVM address (in bytes)
 * @param  pdata		pointer to data to read
 * @param  nbbytes		Bytes number to read
 * @retval None
 */
uint8_t aFramRead(uint16_t Address, void *pdata, uint32_t nbbytes) {
    uint8_t *p = pdata;
    #ifdef USE_FASTREAD
        uint8_t Buffer[4] = {0};
        Buffer[0] = FASTREAD;
        Buffer[3] = DUMMY;
    #else
        uint8_t Buffer[3] = {0};
        Buffer[0] = READ;
    #endif
    Buffer[1] = (uint8_t)((Address & 0xFF00) >> 8);
    Buffer[2] = (uint8_t)(Address & 0x00FF);

    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET);               /* CS = 0 */
    HAL_SPI_Transmit(&hspi, &Buffer[0], sizeof(Buffer), 1000); /* Send SPI a write data opcode */
    WAIT_TX_BUF_EMPTY(hspi);                                   /* Wait for SPI Tx buffer empty */
    HAL_SPI_Receive(&hspi, p, nbbytes, 1000);                  /* Read SPI data */

    HAL_GPIO_WritePin(csPort, csPin, PIN_SET); /* CS=1 */
    HAL_Delay(1);
    // DBG("-I- FRAM - Byte read:  0x%2X 0x%2X 0x%2X 0x%2X   @ 0x%5X\r\n",p[3],p[2],p[1],p[0],Address);
    // DBG("-I- FRAM - Byte read:  %1X %1X %1X %1X   @ 0x%5X\r\n",p[3],p[2],p[1],p[0],Address);
    return 1;
}

uint8_t getDeviceId(void) {
    uint8_t RxBuffer[9] = {0};
    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET); // CS = 0
    HAL_SPI_Transmit(&hspi, &DEVICEID, 1, 1000);
    HAL_SPI_Receive(&hspi, &RxBuffer[0], sizeof(RxBuffer), 1000);
    HAL_GPIO_WritePin(csPort, csPin, PIN_SET); // CS = 1
    return 1;
}

uint8_t getStatusRegister(void) {
    uint8_t status;
    HAL_GPIO_WritePin(csPort, csPin, PIN_RESET); // CS = 0
    HAL_SPI_Transmit(&hspi, &STATUSREGISTER, 1, 1000);
    HAL_SPI_Receive(&hspi, &status, 1, 1000);
    HAL_GPIO_WritePin(csPort, csPin, PIN_SET); // CS = 1
    return status;
}

uint8_t aFramTest32(uint16_t Address, uint32_t data) {
    uint8_t rx[4] = {0};
    // uint8_t status = getStatusRegister();
    // DBG("-I- FRAM - Status: %i\r\n", status);
    aFramInit(hspi2, GPIOE, GPIO_PIN_10);
    while (1) {
        aFramWrite32(Address, data);
        HAL_Delay(1000);
        for (uint8_t i = 0; i < 4; i++)
            rx[i] = 0;
        // DBG("-I- FRAM - erase tab:  0x%2X 0x%2X 0x%2X 0x%2X\r\n", rx[3], rx[2], rx[1], rx[0]);
        aFramRead(Address, &rx, sizeof(rx));
        // DBG("-I- FRAM - Byte read:  0x%2X 0x%2X 0x%2X 0x%2X\r\n", rx[3], rx[2], rx[1], rx[0]);
    }
    return 1;
}

// #endif
