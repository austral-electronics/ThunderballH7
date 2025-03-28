#ifndef CANBUS_H
#define CANBUS_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32h7xx_hal.h"

extern FDCAN_HandleTypeDef hfdcan1;
extern FDCAN_HandleTypeDef hfdcan2;

bool InitCAN1(void);
bool InitCAN2(void);
bool TransmitCAN_Test(FDCAN_HandleTypeDef *hfdcan);

#endif