/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "encoder.h"
#include "pid.h"
#include "timer.h"
#include "trajectory.h"
#include "inverse_kinematics.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
volatile float xi;
volatile float yi;
volatile float zi;

volatile float thetai1;
volatile float thetai2;
volatile float thetai3;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
	ENCODER_SetZero(&ENCODER_1);
	MOTOR_SetRequiredSpeed(&MOTOR_1,0);
	PID_Enable(&PID_0_Pos);

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */
	ENCODER_SetZero(&ENCODER_0);
	MOTOR_SetRequiredSpeed(&MOTOR_0,0);
	PID_Enable(&PID_1_Pos);

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */
	ENCODER_SetZero(&ENCODER_2);
	MOTOR_SetRequiredSpeed(&MOTOR_2,0);
	PID_Enable(&PID_2_Pos);

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break interrupt.
  */
void TIM1_BRK_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_IRQn 0 */

  /* USER CODE END TIM1_BRK_IRQn 0 */
  /* USER CODE BEGIN TIM1_BRK_IRQn 1 */

  /* USER CODE END TIM1_BRK_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_IRQn 0 */
	LL_TIM_DisableCounter(TIM1);
	MOTOR_SetCurrentSpeed(&MOTOR_0);
	MOTOR_SetCurrentSpeed(&MOTOR_1);
	MOTOR_SetCurrentSpeed(&MOTOR_2);

	LL_TIM_EnableCounter(TIM1);
	LL_TIM_ClearFlag_UPDATE(TIM1);

  /* USER CODE END TIM1_UP_IRQn 0 */
  /* USER CODE BEGIN TIM1_UP_IRQn 1 */

  /* USER CODE END TIM1_UP_IRQn 1 */
}

/**
  * @brief This function handles TIM1 trigger and commutation interrupts.
  */
void TIM1_TRG_COM_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_TRG_COM_IRQn 0 */

  /* USER CODE END TIM1_TRG_COM_IRQn 0 */
  /* USER CODE BEGIN TIM1_TRG_COM_IRQn 1 */

  /* USER CODE END TIM1_TRG_COM_IRQn 1 */
}

/**
  * @brief This function handles TIM1 capture compare interrupt.
  */
void TIM1_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_CC_IRQn 0 */

	if(LL_TIM_IsActiveFlag_CC1(TIM1))
	{
		HAL_GPIO_WritePin(MOTOR_0.GPIO_Port_A,MOTOR_0.GPIO_Pin_A,RESET);
		HAL_GPIO_WritePin(MOTOR_0.GPIO_Port_B,MOTOR_0.GPIO_Pin_B,RESET);
		LL_TIM_ClearFlag_CC1(TIM1);
	}

	if(LL_TIM_IsActiveFlag_CC2(TIM1))
	{
		HAL_GPIO_WritePin(MOTOR_1.GPIO_Port_A,MOTOR_1.GPIO_Pin_A,RESET);
		HAL_GPIO_WritePin(MOTOR_1.GPIO_Port_B,MOTOR_1.GPIO_Pin_B,RESET);
		LL_TIM_ClearFlag_CC2(TIM1);
	}

	if(LL_TIM_IsActiveFlag_CC3(TIM1))
	{
		HAL_GPIO_WritePin(MOTOR_2.GPIO_Port_A,MOTOR_2.GPIO_Pin_A,RESET);
		HAL_GPIO_WritePin(MOTOR_2.GPIO_Port_B,MOTOR_2.GPIO_Pin_B,RESET);
		LL_TIM_ClearFlag_CC3(TIM1);
	}
	if(LL_TIM_IsActiveFlag_CC4(TIM1))
	{
		if(TIMER_IsEnabled(&TIMER_0))
		{
			TIMER_IncTimer(&TIMER_0);
			TIMER_UpdateTime(&TIMER_0);
		}

		TRAJECTORY_MakeStep(&TRAJECTORY);

//		delta_calcForward(-ENCODER_GetAbsoluteAngle(&ENCODER_0),-ENCODER_GetAbsoluteAngle(&ENCODER_1),-ENCODER_GetAbsoluteAngle(&ENCODER_2),&xi,&yi,&zi);
//		delta_calcInverse(0.0,0.0,-248.92,&thetai1,&thetai2,&thetai3);

		ENCODER_UpdateAbsoluteAngle(&ENCODER_0);
		ENCODER_UpdateAbsoluteAngle(&ENCODER_1);
		ENCODER_UpdateAbsoluteAngle(&ENCODER_2);

		ENCODER_UpdateAbsoluteAngularVelocity(&ENCODER_0);
		ENCODER_UpdateAbsoluteAngularVelocity(&ENCODER_1);
		ENCODER_UpdateAbsoluteAngularVelocity(&ENCODER_2);

		if(PID_IsEnabled(&PID_0_Pos) && PID_IsEnabled(&PID_1_Pos) && PID_IsEnabled(&PID_2_Pos))
		{
			PID_Disable(&PID_0_Speed);
			PID_Disable(&PID_1_Speed);
			PID_Disable(&PID_2_Speed);

			if(PID_IsEnabled(&PID_0_Pos)) MOTOR_SetRequiredSpeed(&MOTOR_0,PID_Calc(&PID_0_Pos,ENCODER_GetAbsoluteAngle(&ENCODER_0)));
			if(PID_IsEnabled(&PID_1_Pos)) MOTOR_SetRequiredSpeed(&MOTOR_1,PID_Calc(&PID_1_Pos,ENCODER_GetAbsoluteAngle(&ENCODER_1)));
			if(PID_IsEnabled(&PID_2_Pos)) MOTOR_SetRequiredSpeed(&MOTOR_2,PID_Calc(&PID_2_Pos,ENCODER_GetAbsoluteAngle(&ENCODER_2)));
		}
		else if(PID_IsEnabled(&PID_0_Speed) && PID_IsEnabled(&PID_1_Speed) && PID_IsEnabled(&PID_2_Speed))
		{
			if(PID_IsEnabled(&PID_0_Speed)) MOTOR_SetRequiredSpeed(&MOTOR_0,PID_Calc(&PID_0_Speed,	ENCODER_GetAbsoluteAngularVelocity(&ENCODER_0)));
		    if(PID_IsEnabled(&PID_1_Speed)) MOTOR_SetRequiredSpeed(&MOTOR_1,PID_Calc(&PID_1_Speed,	ENCODER_GetAbsoluteAngularVelocity(&ENCODER_1)));
			if(PID_IsEnabled(&PID_2_Speed)) MOTOR_SetRequiredSpeed(&MOTOR_2,PID_Calc(&PID_2_Speed,	ENCODER_GetAbsoluteAngularVelocity(&ENCODER_2)));
		}
		LL_TIM_ClearFlag_CC4(TIM1);


			if(ENCODER_GetAbsoluteAngle(&ENCODER_0)<-45.0)
			{
				MOTOR_SetRequiredSpeed(&MOTOR_0,0);

			}
			if(ENCODER_GetAbsoluteAngle(&ENCODER_1)<-45.0)
			{
				MOTOR_SetRequiredSpeed(&MOTOR_1,0);

			}
			if(ENCODER_GetAbsoluteAngle(&ENCODER_2)<-45.0)
			{
				MOTOR_SetRequiredSpeed(&MOTOR_2,0);
			}

	}
  /* USER CODE END TIM1_CC_IRQn 0 */
  /* USER CODE BEGIN TIM1_CC_IRQn 1 */

  /* USER CODE END TIM1_CC_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  int test;
}

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
