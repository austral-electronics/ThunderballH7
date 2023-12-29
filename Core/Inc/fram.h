/**
 ******************************************************************************
 * @file    Fram.h
 * @author  AUSTRAL Electronic
 * @version V1.0
 * @date    2022
 * @brief   Fram.c definitions
 ******************************************************************************
 *
 * <h2><center>COPYRIGHT 2022 AUSTRAL Electronics </center></h2>
 */
#ifndef FRAM_H
#define FRAM_H

#include "stm32h7xx_hal.h"
#include <stdint.h>
extern SPI_HandleTypeDef hspi2;

#define FRAM_SIZE 0x07FF

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

extern void aFramInit(SPI_HandleTypeDef _hspi, GPIO_TypeDef *, uint16_t);
extern void aFramWrite(uint16_t address, void *pdata, uint32_t nbbytes);
extern void aFramWrite32(uint16_t address, uint32_t data);
extern uint8_t aFramRead(uint16_t Address, void *pdata, uint32_t nbbytes);
extern uint8_t getDeviceId(void);
extern uint8_t getStatusRegister(void);
extern uint8_t aFramTest32(uint16_t Address, uint32_t data);

#endif

/******************* (C) COPYRIGHT 2022 AUSTRAL Electronics *****END OF FILE****/
