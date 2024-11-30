/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define T1_CNT 9999
#define T1_PRE 7199
#define PWM_1 4999
#define red1_Pin GPIO_PIN_5
#define red1_GPIO_Port GPIOE
#define green1_Pin GPIO_PIN_6
#define green1_GPIO_Port GPIOE
#define testing2_Pin GPIO_PIN_13
#define testing2_GPIO_Port GPIOC
#define testing_key_Pin GPIO_PIN_0
#define testing_key_GPIO_Port GPIOA
#define key1_Pin GPIO_PIN_6
#define key1_GPIO_Port GPIOA
#define green4_Pin GPIO_PIN_12
#define green4_GPIO_Port GPIOB
#define red4_Pin GPIO_PIN_13
#define red4_GPIO_Port GPIOB
#define green3_Pin GPIO_PIN_14
#define green3_GPIO_Port GPIOB
#define red3_Pin GPIO_PIN_15
#define red3_GPIO_Port GPIOB
#define key2_Pin GPIO_PIN_11
#define key2_GPIO_Port GPIOC
#define key3_Pin GPIO_PIN_12
#define key3_GPIO_Port GPIOC
#define key4_Pin GPIO_PIN_2
#define key4_GPIO_Port GPIOD
#define green2_Pin GPIO_PIN_6
#define green2_GPIO_Port GPIOB
#define red2_Pin GPIO_PIN_7
#define red2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
