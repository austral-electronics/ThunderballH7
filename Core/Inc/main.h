/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define ADC1_12V_Pin GPIO_PIN_6
#define ADC1_12V_GPIO_Port GPIOA
#define BIT4_Pin GPIO_PIN_0
#define BIT4_GPIO_Port GPIOB
#define BIT5_Pin GPIO_PIN_1
#define BIT5_GPIO_Port GPIOB
#define UART7_RTS_Pin GPIO_PIN_9
#define UART7_RTS_GPIO_Port GPIOE
#define UART7_CTS_Pin GPIO_PIN_10
#define UART7_CTS_GPIO_Port GPIOE
#define BIT0_Pin GPIO_PIN_11
#define BIT0_GPIO_Port GPIOE
#define BIT1_Pin GPIO_PIN_12
#define BIT1_GPIO_Port GPIOE
#define BIT2_Pin GPIO_PIN_13
#define BIT2_GPIO_Port GPIOE
#define BIT3_Pin GPIO_PIN_14
#define BIT3_GPIO_Port GPIOE
#define ADC1_TEMP_Pin GPIO_PIN_15
#define ADC1_TEMP_GPIO_Port GPIOE
#define BIT6_Pin GPIO_PIN_10
#define BIT6_GPIO_Port GPIOB
#define UART4_HF_Pin GPIO_PIN_15
#define UART4_HF_GPIO_Port GPIOB
#define USART3_HF_Pin GPIO_PIN_10
#define USART3_HF_GPIO_Port GPIOD
#define BIT7_Pin GPIO_PIN_11
#define BIT7_GPIO_Port GPIOD
#define CMD_LED_Pin GPIO_PIN_7
#define CMD_LED_GPIO_Port GPIOC
#define UART5_HF_Pin GPIO_PIN_9
#define UART5_HF_GPIO_Port GPIOC
#define USART2_HF_Pin GPIO_PIN_3
#define USART2_HF_GPIO_Port GPIOD
#define SPI1_SCK_Pin GPIO_PIN_3
#define SPI1_SCK_GPIO_Port GPIOB
#define SPI1_MISO_Pin GPIO_PIN_4
#define SPI1_MISO_GPIO_Port GPIOB
#define SPI1_MOSI_Pin GPIO_PIN_5
#define SPI1_MOSI_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
