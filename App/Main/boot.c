/**
 * --------------------------------------------------------------------
 * @file    boot.c
 * @author  Austral Electronics
 * @version V1.0
 * @date    14/04/2022
 * @brief   Thunderball H7 Bootload functions
 * -------------------------------------------------------------------- */

#include "common.h"

void JumpToBootloader(void){
    for (uint32_t i=0;i<21;i++) {for (uint64_t j=0;j<10000000;j++) {} HAL_GPIO_TogglePin(CMD_LED_GPIO_Port, CMD_LED_Pin);} // Blink Backlight

    void (*SysMemBootJump)(void);
    volatile uint32_t BootAddr = 0x1FF09800;  // Bootloader Address
    __disable_irq();                          // Disable all interrupts
    SysTick->CTRL = 0;                        // Disable Systick timer
    HAL_RCC_DeInit();                         // Set the clock to the default state
    for (uint32_t i=0;i<5;i++) {              // Clear Interrupt Enable Register & Interrupt Pending Register
        NVIC->ICER[i]=0xFFFFFFFF;
        NVIC->ICPR[i]=0xFFFFFFFF;
     }  
     __enable_irq();                          // Re-enable all interrupts
     SysMemBootJump = (void (*)(void)) (*((uint32_t *) ((BootAddr + 4))));  // Set up the jump to booloader address + 4
     __set_MSP(*(uint32_t *)BootAddr);        // Set the main stack pointer to the bootloader stack
     SysMemBootJump();                        // Call the function to jump to bootloader location
}