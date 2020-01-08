#ifndef ENCODER_H
#define	ENCODER_H

#include "main.h"
#include "motor.h"

#define ENCODER_CNT_MAX					65535
//#define ENCODER_END_ANGLE				(float)(46.5525 + 2.249)
//#define ENCODER_END_ANGLE				(float)(52.01)
//#define ENCODER_END_ANGLE				(float)(46.5525)
#define ENCODER_END_ANGLE				(float)(49.28)
#define ENCODER_RESOLUTION				2400
#define ENCODER_FULL_ANGLE_RESOLUTION	((float)(ENCODER_RESOLUTION*MOTOR_TRANSMISSION)/(float)360.0)
#define ENCODER_TIM_ZERO_VALUE			(ENCODER_CNT_MAX - (90.0-ENCODER_END_ANGLE)*ENCODER_FULL_ANGLE_RESOLUTION)
#define ENCODER_TIM_ZERO_VALUE_UINT		(int32_t)(ENCODER_TIM_ZERO_VALUE)


typedef struct
{
	TIM_TypeDef*			TIM;
	float 					previousAngle;
	float 					actualAngle;
	float 					AngularSpeed;

}ENCODER_TypeDef;

extern ENCODER_TypeDef	ENCODER_0;
extern ENCODER_TypeDef	ENCODER_1;
extern ENCODER_TypeDef	ENCODER_2;

void  ENCODER_Init();
float ENCODER_GetAbsoluteAngle(ENCODER_TypeDef* ENCODER);
void  ENCODER_UpdateAbsoluteAngle(ENCODER_TypeDef* ENCODER);
void  ENCODER_UpdateAbsoluteAngularVelocity(ENCODER_TypeDef* ENCODER);
float ENCODER_GetAbsoluteAngularVelocity(ENCODER_TypeDef* ENCODER);
void  ENCODER_SetZero(ENCODER_TypeDef* ENCODER);



#endif
