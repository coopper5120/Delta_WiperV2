#include "motor.h"
#include "stm32f1xx_ll_tim.h"


MOTOR_TypeDef	MOTOR_0;
MOTOR_TypeDef	MOTOR_1;
MOTOR_TypeDef	MOTOR_2;

void MOTOR_SetRequiredSpeed(MOTOR_TypeDef* MOTOR, int16_t speed)
{

//	DEAD ZONE
	if(speed > 0)
	{
		speed+= MOTOR->deadZoneForward;
	}
	else if(speed < 0)
	{
			speed-= MOTOR->deadZoneBackward;
	}

	speed = speed * MOTOR->polarization;

	if(speed > 0)
	{
			MOTOR->direction = FORWARD;
	}
	else if(speed < 0)
	{
			MOTOR->direction = BACKWARD;
	}
	else MOTOR->direction = STOP;


	//SATURATION
	if(speed > 0 && speed >  MOTOR_PULSE_MAX) 		MOTOR->speed =  MOTOR_PULSE_MAX;
	else if(speed < 0 && (-speed) >  MOTOR_PULSE_MAX) 	MOTOR->speed = -MOTOR_PULSE_MAX;
	else MOTOR->speed = speed;
//	 MOTOR->speed = speed;

}

void MOTOR_SetCurrentSpeed(MOTOR_TypeDef* MOTOR)
{
	uint16_t pulseLength;

	// AVOIDING H BRIDGE BURN/////////////////////////////////
	if(MOTOR->previousDirection != MOTOR->direction)
	{
		HAL_GPIO_WritePin(MOTOR->GPIO_Port_B,MOTOR->GPIO_Pin_B,RESET);
		HAL_GPIO_WritePin(MOTOR->GPIO_Port_A,MOTOR->GPIO_Pin_A,RESET);
	}
	//////////////////////////////////////////////////////////
	else
	{
		if(MOTOR->direction == FORWARD)
		{
			pulseLength = (MOTOR->speed * LL_TIM_GetAutoReload(MOTOR->TIM)/ MOTOR_PULSE_MAX)-1;
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_B,MOTOR->GPIO_Pin_B,RESET);
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_A,MOTOR->GPIO_Pin_A,SET);
		}
		else if(MOTOR->direction == BACKWARD)
		{
			pulseLength = ((-MOTOR->speed) * LL_TIM_GetAutoReload(MOTOR->TIM)/ MOTOR_PULSE_MAX)-1;
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_A,MOTOR->GPIO_Pin_A,RESET);
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_B,MOTOR->GPIO_Pin_B,SET);
		}
		else if(MOTOR->direction == STOP)
		{
			pulseLength = 0;
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_A,MOTOR->GPIO_Pin_A,RESET);
			HAL_GPIO_WritePin(MOTOR->GPIO_Port_B,MOTOR->GPIO_Pin_B,RESET);
		}
	}
//	LL_TIM_SetCounter(MOTOR->TIM, 0);
	WRITE_REG(*MOTOR->CCR,pulseLength);

	MOTOR->previousDirection = MOTOR->direction;
}

void MOTOR_Init()
{
	MOTOR_0.GPIO_Port_A = MOTOR_0A_GPIO_Port;
	MOTOR_0.GPIO_Pin_A = MOTOR_0A_Pin;
	MOTOR_0.GPIO_Port_B = MOTOR_0B_GPIO_Port;
	MOTOR_0.GPIO_Pin_B =  MOTOR_0B_Pin;
	MOTOR_0.TIM = TIM1;
	MOTOR_0.CCR = &(TIM1->CCR1);
	MOTOR_0.direction = FORWARD;
	MOTOR_0.previousDirection = FORWARD;
	MOTOR_0.speed = 0;
	MOTOR_0.polarization = MOTOR_0_POLARIZATION;
	MOTOR_0.deadZoneForward = 20;
	MOTOR_0.deadZoneBackward = 5;

	MOTOR_1.GPIO_Port_A = MOTOR_1A_GPIO_Port;
	MOTOR_1.GPIO_Pin_A = MOTOR_1A_Pin;
	MOTOR_1.GPIO_Port_B = MOTOR_1B_GPIO_Port;
	MOTOR_1.GPIO_Pin_B =  MOTOR_1B_Pin;
	MOTOR_1.TIM = TIM1;
	MOTOR_1.CCR = &(TIM1->CCR2);
	MOTOR_1.direction = FORWARD;
	MOTOR_1.previousDirection = FORWARD;
	MOTOR_1.speed = 0;
	MOTOR_1.polarization = MOTOR_1_POLARIZATION;
	MOTOR_1.deadZoneForward = 20;
	MOTOR_1.deadZoneBackward = 5;

	MOTOR_2.GPIO_Port_A = MOTOR_2A_GPIO_Port;
	MOTOR_2.GPIO_Pin_A = MOTOR_2A_Pin;
	MOTOR_2.GPIO_Port_B = MOTOR_2B_GPIO_Port;
	MOTOR_2.GPIO_Pin_B =  MOTOR_2B_Pin;
	MOTOR_2.TIM = TIM1;
	MOTOR_2.CCR = &(TIM1->CCR3);
	MOTOR_2.direction = FORWARD;
	MOTOR_2.previousDirection = FORWARD;
	MOTOR_2.speed = 0;
	MOTOR_2.polarization = MOTOR_2_POLARIZATION;
	MOTOR_2.deadZoneForward = 20;
	MOTOR_2.deadZoneBackward = 5;
}
