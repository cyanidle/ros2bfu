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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MotorD_DIR_Pin GPIO_PIN_0
#define MotorD_DIR_GPIO_Port GPIOA
#define MotorD_INT_Pin GPIO_PIN_1
#define MotorD_INT_GPIO_Port GPIOA
#define MotorB_DIR_Pin GPIO_PIN_6
#define MotorB_DIR_GPIO_Port GPIOA
#define MotorB_INT_Pin GPIO_PIN_7
#define MotorB_INT_GPIO_Port GPIOA
#define MotorB_INT_EXTI_IRQn EXTI9_5_IRQn
#define MotorA_INT_Pin GPIO_PIN_15
#define MotorA_INT_GPIO_Port GPIOA
#define MotorA_INT_EXTI_IRQn EXTI15_10_IRQn
#define MotorA_DIR_Pin GPIO_PIN_3
#define MotorA_DIR_GPIO_Port GPIOB
#define MotorC_INT_Pin GPIO_PIN_6
#define MotorC_INT_GPIO_Port GPIOB
#define MotorC_INT_EXTI_IRQn EXTI9_5_IRQn
#define MotorC_DIR_Pin GPIO_PIN_7
#define MotorC_DIR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
