#include "encoder.h"

ENCODER_TypeDef	ENCODER_0;
ENCODER_TypeDef	ENCODER_1;
ENCODER_TypeDef	ENCODER_2;

void ENCODER_Init()
{
	ENCODER_0.TIM = TIM2;
	ENCODER_1.TIM = TIM3;
	ENCODER_2.TIM = TIM4;

	ENCODER_SetZero(&ENCODER_0);			// zerowanie zeby nie przekrecic timera podczas dojezdzaniu predkosciowym do krancowek
	ENCODER_SetZero(&ENCODER_1);
	ENCODER_SetZero(&ENCODER_2);

//	ENCODER_0.globalAngle = 0;

	ENCODER_0.previousAngle = 0;
	ENCODER_0.actualAngle = 0;
	ENCODER_0.AngularSpeed = 0;

	ENCODER_1.previousAngle = 0;
	ENCODER_1.actualAngle = 0;
	ENCODER_1.AngularSpeed = 0;

	ENCODER_2.previousAngle = 0;
	ENCODER_2.actualAngle = 0;
	ENCODER_2.AngularSpeed = 0;
}

void ENCODER_SetZero(ENCODER_TypeDef* ENCODER)
{
	LL_TIM_SetCounter(ENCODER->TIM,(uint16_t)(ENCODER_TIM_ZERO_VALUE));
}


float ENCODER_GetAbsoluteAngle(ENCODER_TypeDef* ENCODER)
{
	int32_t actualCounterValue = (int32_t)LL_TIM_GetCounter(ENCODER->TIM);
	return (ENCODER_END_ANGLE + (float)(actualCounterValue - ENCODER_TIM_ZERO_VALUE_UINT)/ENCODER_FULL_ANGLE_RESOLUTION);
}

void ENCODER_UpdateAbsoluteAngle(ENCODER_TypeDef* ENCODER)
{
	ENCODER->previousAngle = ENCODER->actualAngle;
	ENCODER->actualAngle = ENCODER_GetAbsoluteAngle(ENCODER);
}
void  ENCODER_UpdateAbsoluteAngularVelocity(ENCODER_TypeDef* ENCODER)
{
	ENCODER->AngularSpeed = (ENCODER->actualAngle - ENCODER->previousAngle)/dt;
}

float ENCODER_GetAbsoluteAngularVelocity(ENCODER_TypeDef* ENCODER)
{
	return ENCODER->AngularSpeed;
}
