/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_dma.h"

#include "stm32f1xx_ll_exti.h"

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
#define dt	0.01
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_2A_Pin GPIO_PIN_13
#define MOTOR_2A_GPIO_Port GPIOC
#define USER_ENCODER_B_Pin GPIO_PIN_14
#define USER_ENCODER_B_GPIO_Port GPIOC
#define USER_ENCODER_A_Pin GPIO_PIN_15
#define USER_ENCODER_A_GPIO_Port GPIOC
#define CURRENT_SENSE_0_Pin GPIO_PIN_0
#define CURRENT_SENSE_0_GPIO_Port GPIOA
#define CURRENT_SENSE_1_Pin GPIO_PIN_1
#define CURRENT_SENSE_1_GPIO_Port GPIOA
#define CURRENT_SENSE_2_Pin GPIO_PIN_4
#define CURRENT_SENSE_2_GPIO_Port GPIOA
#define ENDSTOP_2_Pin GPIO_PIN_5
#define ENDSTOP_2_GPIO_Port GPIOA
#define ENDSTOP_2_EXTI_IRQn EXTI9_5_IRQn
#define MOTOR_2B_Pin GPIO_PIN_6
#define MOTOR_2B_GPIO_Port GPIOA
#define MOTOR_1B_Pin GPIO_PIN_7
#define MOTOR_1B_GPIO_Port GPIOA
#define ENDSTOP_1_Pin GPIO_PIN_0
#define ENDSTOP_1_GPIO_Port GPIOB
#define ENDSTOP_1_EXTI_IRQn EXTI0_IRQn
#define ENDSTOP_0_Pin GPIO_PIN_1
#define ENDSTOP_0_GPIO_Port GPIOB
#define ENDSTOP_0_EXTI_IRQn EXTI1_IRQn
#define SPI2_CS1_Pin GPIO_PIN_10
#define SPI2_CS1_GPIO_Port GPIOB
#define USER_ENCODER_BUTTON_Pin GPIO_PIN_11
#define USER_ENCODER_BUTTON_GPIO_Port GPIOB
#define SPI2_CS0_Pin GPIO_PIN_12
#define SPI2_CS0_GPIO_Port GPIOB
#define MOTOR_1A_Pin GPIO_PIN_8
#define MOTOR_1A_GPIO_Port GPIOA
#define MOTOR_0B_Pin GPIO_PIN_9
#define MOTOR_0B_GPIO_Port GPIOA
#define MOTOR_0A_Pin GPIO_PIN_10
#define MOTOR_0A_GPIO_Port GPIOA
#define ENCODER_0A_Pin GPIO_PIN_15
#define ENCODER_0A_GPIO_Port GPIOA
#define ENCODER_0B_Pin GPIO_PIN_3
#define ENCODER_0B_GPIO_Port GPIOB
#define ENCODER_1A_Pin GPIO_PIN_4
#define ENCODER_1A_GPIO_Port GPIOB
#define ENCODER_1B_Pin GPIO_PIN_5
#define ENCODER_1B_GPIO_Port GPIOB
#define ENCODER_2A_Pin GPIO_PIN_6
#define ENCODER_2A_GPIO_Port GPIOB
#define ENCODER_2B_Pin GPIO_PIN_7
#define ENCODER_2B_GPIO_Port GPIOB
#define TOOL_0_Pin GPIO_PIN_8
#define TOOL_0_GPIO_Port GPIOB
#define TOOL_1_Pin GPIO_PIN_9
#define TOOL_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
