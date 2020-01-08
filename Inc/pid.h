#ifndef PID_H
#define PID_H

#include "motor.h"
#include "encoder.h"
#include <stdbool.h>

typedef struct
{
	float r;
	float e;
	float Kp;
	float Kd;
	float Ki;
	float integral;
	float previousErrorValue;
	bool enable;
	int16_t u;
}PID_TypeDef;

extern PID_TypeDef PID_0_Pos;
extern PID_TypeDef PID_1_Pos;
extern PID_TypeDef PID_2_Pos;

extern PID_TypeDef PID_0_Speed;
extern PID_TypeDef PID_1_Speed;
extern PID_TypeDef PID_2_Speed;

int16_t	PID_Calc(PID_TypeDef* PID, float y);
void 	PID_init();
void 	PID_SetRequired(PID_TypeDef* PID, float position);
void 	PID_Enable(PID_TypeDef* PID);
void 	PID_Disable(PID_TypeDef* PID);
bool 	PID_IsEnabled(PID_TypeDef* PID);

#endif	PID_H
