#ifndef	TIMER_H
#define TIMER_H

#include "main.h"
#include <stdbool.h>

typedef struct
{
	volatile 	uint32_t ticks;
	volatile 	float time;
	bool		enable;
}TIMER_TypeDef;

extern TIMER_TypeDef TIMER_0;

void 	 TIMER_Init(TIMER_TypeDef* TIMER);
void 	 TIMER_IncTimer(TIMER_TypeDef* TIMER);
void 	 TIMER_SetZero(TIMER_TypeDef* TIMER);
uint32_t TIMER_GetTicks(TIMER_TypeDef* TIMER);
float    TIMER_GetTime(TIMER_TypeDef* TIMER);
void     TIMER_UpdateTime(TIMER_TypeDef* TIMER);
void     TIMER_Enable(TIMER_TypeDef* TIMER);
void     TIMER_Disable(TIMER_TypeDef* TIMER);
bool	 TIMER_IsEnabled(TIMER_TypeDef* TIMER);

#endif
