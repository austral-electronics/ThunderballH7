/**
 * --------------------------------------------------------------------
 * @file    boot.h
 * @author  Austral Electronics
 * @version V1.0
 * @date    14/04/2022
 * @brief   Thunderball H7 Bootload functions
 * -------------------------------------------------------------------- */


#ifndef RETARGET_STDIO_H
#define RETARGET_STDIO_H

extern UART_HandleTypeDef huart7;

__attribute__((weak)) int __io_putchar(int ch);


#endif