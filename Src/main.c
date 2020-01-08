/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "adc.h"
#include "fatfs.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include "encoder.h"
#include "pid.h"
#include "timer.h"
#include "inverse_kinematics.h"
#include "trajectory.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
float theta1;
float theta2;
float theta3;

float x0 = 0.0;
float y0 = 0.0;
float z0 = -360.0;

float x1 = 0.0;
float y1 = 0.0;
float z1 = -300.0;

float x2 = 0.0;
float y2 = 0.0;
float z2 = -200.0;

float i = 0.0;

volatile float xi;
volatile float yi;
volatile float zi;

float old_x;
float old_y;

float new_x;
float new_y;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	// TODO:
	// programowe krancowki
	// wyrzucenie strefy nievzułości z silnika
	// enkoder zwraca predkosc
	// set zero enkodera na poczatku ruchu zeby nie bylo przeskokow kata
	// dojezdzanie do krancowek ze stala przedkoscia, nie moca
	// na podstawie dojezdzania do krancowek, wyznaczana strefa nieczulosci

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART2_UART_Init();
  MX_USB_PCD_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */
  TIMER_Init(&TIMER_0);
  ENCODER_Init();
  MOTOR_Init();
  PID_init();
  TRAJECTORY_Init();
//  SysTick_Config(SystemCoreClock / 1000);
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
//  LL_TIM_EnableIT_UPDATE(TIM2);
//  LL_TIM_EnableIT_UPDATE(TIM3);
//  LL_TIM_EnableIT_UPDATE(TIM4);
  LL_TIM_EnableCounter(TIM1);
  LL_TIM_EnableIT_UPDATE(TIM1);
  LL_TIM_EnableIT_CC1(TIM1);
  LL_TIM_EnableIT_CC2(TIM1);
  LL_TIM_EnableIT_CC3(TIM1);
  LL_TIM_EnableIT_CC4(TIM1);
  TIMER_Enable(&TIMER_0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  MOTOR_SetRequiredSpeed(&MOTOR_0,10); // minus ok // plus nie
//  MOTOR_SetRequiredSpeed(&MOTOR_1,10);	//plus ok // minus nie
//  MOTOR_SetRequiredSpeed(&MOTOR_2,10);  //plus ok //minus ok

	  for(int64_t i = 0; i<3000000; i++) 	{asm("nop");}

	  PID_Enable(&PID_0_Speed);
	  PID_Enable(&PID_1_Speed);
	  PID_Enable(&PID_2_Speed);
  	  PID_SetRequired(&PID_0_Speed, 10);
  	  PID_SetRequired(&PID_1_Speed, 10);
  	  PID_SetRequired(&PID_2_Speed, 10);

//  	for(int64_t i = 0; i<30000000; i++) 	{asm("nop");}


  	  while(!PID_IsEnabled(&PID_0_Pos) || !PID_IsEnabled(&PID_1_Pos)  || !PID_IsEnabled(&PID_2_Pos));
	  delta_calcForward(-ENCODER_GetAbsoluteAngle(&ENCODER_0),-ENCODER_GetAbsoluteAngle(&ENCODER_1),-ENCODER_GetAbsoluteAngle(&ENCODER_2),&xi,&yi,&zi);
	  TRAJECTORY_SetTrajectory(&TRAJECTORY,xi,yi,zi, 50.0*sin(5*i + 3.14/4), 50.0*sin(4*i), -326.5, 3.0);
	  TRAJECTORY_StartTrajectory(&TRAJECTORY);

//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, 0.0, 0.0, -320.0, 10.0, 0.0,-327.0, 20.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);



//	  HAL_Delay(3000);
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  delta_calcForward(-ENCODER_GetAbsoluteAngle(&ENCODER_0),-ENCODER_GetAbsoluteAngle(&ENCODER_1),-ENCODER_GetAbsoluteAngle(&ENCODER_2),&xi,&yi,&zi);

//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, 0.0, 0.0, -320.0, 10.0, 0.0,-320.0, 20.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);

	  old_x =50.0*sin(5*i + 3.14/4);
	  old_y =50.0*sin(9*i);
	  i+= 0.01;
	  new_x =50.0*sin(5*i + 3.14/4);
	  new_y =50.0*sin(9*i);


	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  delta_calcForward(-ENCODER_GetAbsoluteAngle(&ENCODER_0),-ENCODER_GetAbsoluteAngle(&ENCODER_1),-ENCODER_GetAbsoluteAngle(&ENCODER_2),&xi,&yi,&zi);
	  TRAJECTORY_SetTrajectory(&TRAJECTORY, old_x, old_y, -327.5, new_x, new_y,-327.5, 5.0);
	  TRAJECTORY_StartTrajectory(&TRAJECTORY);


//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, -50.0, 0.0,-327.0, -10.0, 70.0, -327.0, 5.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);
//
//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, -10.0, 70.0, -327.0, 10.0, 0.0,-327.0, 5.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);
//
//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, 10.0, 0.0,-327.0, 30.0, 20.0,-327.0, 5.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);
//
//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, 30.0, 20.0,-327.0, -10.0, 70.0,-327.0, 5.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY);
//
//	  while(TRAJECTORY_IsBusy(&TRAJECTORY));
//	  TRAJECTORY_SetTrajectory(&TRAJECTORY, -10.0, 70.0,-327.0, 10.0, 0.0,-327.0, 5.0);
//	  TRAJECTORY_StartTrajectory(&TRAJECTORY)

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
