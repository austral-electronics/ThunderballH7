/**
 * --------------------------------------------------------------------
 * @file    autotest.h
 * @author  Austral Electronics
 * @version V1.0
 * @date    14/04/2022
 * @brief   Thunderball H7 Autotest functions
 * -------------------------------------------------------------------- */


#ifndef AUTOTEST_H
#define AUTOTEST_H

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3; 
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart7;
extern RTC_HandleTypeDef hrtc;

void AutotestFram(void);
void AutotestPooling(void);

#endif
