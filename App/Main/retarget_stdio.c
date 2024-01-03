/**
 * --------------------------------------------------------------------
 * @file    boot.c
 * @author  Austral Electronics
 * @version V1.0
 * @date    14/04/2022
 * @brief   Thunderball H7 Bootload functions
 * -------------------------------------------------------------------- */

#include "common.h"


/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
__attribute__((weak)) int __io_putchar(int ch)
{
    HAL_StatusTypeDef status = HAL_UART_Transmit(&huart7, (uint8_t *)&ch, 1, 0xFFFF);
    return (status == HAL_OK ? ch : 0);
}