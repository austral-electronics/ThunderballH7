/**
 ******************************************************************************
 * @file    fram.h
 * @author  Austral Electronics
 * @version V1.0
 * @date    22/03/2022
 * @brief   Thunderball H7 fram definitions
 ******************************************************************************
 *
 * 
 */
#ifndef FRAM_H
#define FRAM_H

#include "stm32h7xx_hal.h"
#include <stdint.h>

extern SPI_HandleTypeDef hspi1;

// #define FRAM_SIZE 0x7FFF    /* Size of the FM25V02A */
#define FRAM_SIZE 0x7FF     /* Size of the FM25L16B */

/** @defgroup macro
 * @{
 */
#define WAIT_TX_BUF_EMPTY(_hspi)                                                                                                                               \
    while (_hspi.State == HAL_SPI_STATE_BUSY_TX)                                                                                                               \
        ;


/**
 * @brief  GPIO Bit SET and Bit RESET enumeration
 */
typedef enum { PIN_RESET = 0, PIN_SET } PinState;
/**
 * @}
 */

extern void FramInit(SPI_HandleTypeDef _hspi, GPIO_TypeDef *, uint16_t);
extern void FramWrite(uint16_t address, void *pdata, uint32_t nbbytes);
extern void FramWrite32(uint16_t address, uint32_t data);
extern uint8_t FramRead(uint16_t Address, void *pdata, uint32_t nbbytes);
extern uint8_t getDeviceId(void);
extern uint8_t getStatusRegister(void);
extern uint8_t FramTest32(uint16_t Address, uint32_t data);

#endif
