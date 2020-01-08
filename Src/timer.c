#include "timer.h"

TIMER_TypeDef TIMER_0;

void TIMER_IncTimer(TIMER_TypeDef* TIMER)
{
	TIMER->ticks++;
}

void TIMER_SetZero(TIMER_TypeDef* TIMER)
{
	TIMER->ticks = 0;
}

uint32_t TIMER_GetTicks(TIMER_TypeDef* TIMER)
{
	return TIMER->ticks;
}

float TIMER_GetTime(TIMER_TypeDef* TIMER)
{
	return TIMER->time;
}

void TIMER_Init(TIMER_TypeDef* TIMER)
{
	TIMER_SetZero(TIMER);
	TIMER->enable = false;
}

void     TIMER_UpdateTime(TIMER_TypeDef* TIMER)
{
	TIMER->time = (float)TIMER->ticks * dt;
}

void     TIMER_Enable(TIMER_TypeDef* TIMER)
{
	TIMER->enable = true;
}

void     TIMER_Disable(TIMER_TypeDef* TIMER)
{
	TIMER->enable = false;
}

bool	 TIMER_IsEnabled(TIMER_TypeDef* TIMER)
{
	return TIMER->enable;
}

