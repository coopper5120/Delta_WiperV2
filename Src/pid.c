#include "pid.h"


PID_TypeDef PID_0_Pos;
PID_TypeDef PID_1_Pos;
PID_TypeDef PID_2_Pos;

PID_TypeDef PID_0_Speed;
PID_TypeDef PID_1_Speed;
PID_TypeDef PID_2_Speed;

int16_t	PID_Calc(PID_TypeDef* PID, float y)
{
	PID->e = PID->r - y;
	PID->integral += PID->e  * PID->Ki * dt;
	PID->u = (int16_t)(PID->e  * PID->Kp  + PID->integral);

	if(PID->u >  MOTOR_PULSE_MAX) PID->u = MOTOR_PULSE_MAX;
	else if(PID->u <  -MOTOR_PULSE_MAX)	PID->u = -MOTOR_PULSE_MAX;

	if(PID->integral > MOTOR_PULSE_MAX) PID->integral = MOTOR_PULSE_MAX;
	else if(PID->integral < -MOTOR_PULSE_MAX) PID->integral = -MOTOR_PULSE_MAX;

	PID->previousErrorValue = PID->e;
	return PID->u;
}

void PID_init()
{

	// POS
	PID_0_Pos.r = 0;
	PID_0_Pos.Kp = 20.0;
	PID_0_Pos.Kd = 0.0;
	PID_0_Pos.Ki = 10.0;
	PID_0_Pos.integral = 0;
	PID_0_Pos.previousErrorValue = 0;
	PID_0_Pos.enable = false;
	PID_0_Pos.u = 0;
	PID_0_Pos.e = 0;

	PID_1_Pos.r = 0;
	PID_1_Pos.Kp = 20.0;
	PID_1_Pos.Kd = 0.0;
	PID_1_Pos.Ki = 10.0;
	PID_1_Pos.integral = 0;
	PID_1_Pos.previousErrorValue = 0;
	PID_1_Pos.enable = false;
	PID_1_Pos.u = 0;
	PID_1_Pos.e = 0;

	PID_2_Pos.r = 0;
	PID_2_Pos.Kp = 20.0;
	PID_2_Pos.Kd = 0.0;
	PID_2_Pos.Ki = 10.0;
	PID_2_Pos.integral = 0;
	PID_2_Pos.previousErrorValue = 0;
	PID_2_Pos.enable = false;
	PID_2_Pos.u = 0;
	PID_2_Pos.e = 0;

	//SPEED
	PID_0_Speed.r = 0;
	PID_0_Speed.Kp = 1.0;
	PID_0_Speed.Kd = 0.0;
	PID_0_Speed.Ki = 1.0;
	PID_0_Speed.integral = 0;
	PID_0_Speed.previousErrorValue = 0;
	PID_0_Speed.enable = false;
	PID_0_Speed.u = 0;
	PID_0_Speed.e = 0;

	PID_1_Speed.r = 0;
	PID_1_Speed.Kp = 1.0;
	PID_1_Speed.Kd = 0.0;
	PID_1_Speed.Ki = 1.0;
	PID_1_Speed.integral = 0;
	PID_1_Speed.previousErrorValue = 0;
	PID_1_Speed.enable = false;
	PID_1_Speed.u = 0;
	PID_1_Speed.e = 0;

	PID_2_Speed.r = 0;
	PID_2_Speed.Kp = 1.0;
	PID_2_Speed.Kd = 0.0;
	PID_2_Speed.Ki = 1.0;
	PID_2_Speed.integral = 0;
	PID_2_Speed.previousErrorValue = 0;
	PID_2_Speed.enable = false;
	PID_2_Speed.u = 0;
	PID_2_Speed.e = 0;
}

void PID_Enable(PID_TypeDef* PID)
{
	PID->enable = true;
}

void PID_Disable(PID_TypeDef* PID)
{
	PID->enable = false;
}

bool PID_IsEnabled(PID_TypeDef* PID)
{
	return PID->enable;
}

void PID_SetRequired(PID_TypeDef* PID, float position)
{
	PID->r = position;
}

