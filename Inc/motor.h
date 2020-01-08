#ifndef MOTOR_H
#define	MOTOR_H

#include "main.h"
#include <stdbool.h>

#define MOTOR_PULSE_MAX				100
#define MOTOR_DEAD_TIME_TICKS		7200000
#define MOTOR_TRANSMISSION			55
//#define MOTOR_TRANSMISSION			54
#define FORWARD						1
#define BACKWARD					2
#define STOP						0

#define MOTOR_0_POLARIZATION				 -1
#define MOTOR_1_POLARIZATION				1
#define MOTOR_2_POLARIZATION				1

typedef struct
{
	GPIO_TypeDef*			GPIO_Port_A;
	GPIO_TypeDef*			GPIO_Port_B;
	uint16_t 				GPIO_Pin_A;
	uint16_t 				GPIO_Pin_B;
	TIM_TypeDef*			TIM;
	volatile uint32_t*		CCR;
	uint8_t					direction;
	uint8_t					previousDirection;
	int16_t					speed;
	int8_t 					polarization;
	int16_t					deadZoneForward;
	int16_t					deadZoneBackward;


//	float			angularPosition;
}MOTOR_TypeDef;

extern MOTOR_TypeDef	MOTOR_0;
extern MOTOR_TypeDef	MOTOR_1;
extern MOTOR_TypeDef	MOTOR_2;

void MOTOR_Init();
void MOTOR_SetRequiredSpeed(MOTOR_TypeDef* MOTOR, int16_t speed);
void MOTOR_SetCurrentSpeed(MOTOR_TypeDef* MOTOR);


#endif
