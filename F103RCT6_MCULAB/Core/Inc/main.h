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
#define ROW5_Pin GPIO_PIN_13
#define ROW5_GPIO_Port GPIOC
#define ROW6_Pin GPIO_PIN_14
#define ROW6_GPIO_Port GPIOC
#define ROW7_Pin GPIO_PIN_15
#define ROW7_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOC
#define SEG2_Pin GPIO_PIN_4
#define SEG2_GPIO_Port GPIOA
#define ROW0_Pin GPIO_PIN_5
#define ROW0_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_4
#define LED5_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_5
#define LED6_GPIO_Port GPIOC
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define ENM2_Pin GPIO_PIN_10
#define ENM2_GPIO_Port GPIOB
#define ENM3_Pin GPIO_PIN_11
#define ENM3_GPIO_Port GPIOB
#define ENM4_Pin GPIO_PIN_12
#define ENM4_GPIO_Port GPIOB
#define ENM5_Pin GPIO_PIN_13
#define ENM5_GPIO_Port GPIOB
#define ENM6_Pin GPIO_PIN_14
#define ENM6_GPIO_Port GPIOB
#define ENM7_Pin GPIO_PIN_15
#define ENM7_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define ROW1_Pin GPIO_PIN_10
#define ROW1_GPIO_Port GPIOA
#define ROW2_Pin GPIO_PIN_11
#define ROW2_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_12
#define ROW3_GPIO_Port GPIOA
#define ROW4_Pin GPIO_PIN_15
#define ROW4_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_4
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_5
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_6
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_7
#define SEG6_GPIO_Port GPIOB
#define ENM0_Pin GPIO_PIN_8
#define ENM0_GPIO_Port GPIOB
#define ENM1_Pin GPIO_PIN_9
#define ENM1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
