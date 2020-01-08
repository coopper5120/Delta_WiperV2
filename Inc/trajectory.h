#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <stdbool.h>

typedef struct
{
	float xCurrent;
	float yCurrent;
	float zCurrent;

	float xTarget;
	float yTarget;
	float zTarget;

	float xStart;
	float yStart;
	float zStart;

	float xLength;
	float yLength;
	float zLength;

	float velocity;
	float totalTime;
	float trackLength;

	float timeStart;
	float time;

	float theta0;
	float theta1;
	float theta2;

	float minustheta0;
	float minustheta1;
	float minustheta2;

	bool busy;

}TRAJECTORY_TypeDef;

extern TRAJECTORY_TypeDef TRAJECTORY;

void TRAJECTORY_Init();
void TRAJECTORY_SetTrajectory(TRAJECTORY_TypeDef* TRAJECTORY, float x0, float y0, float z0, float xk, float yk, float zk, float velocity);
bool TRAJECTORY_StartTrajectory(TRAJECTORY_TypeDef* TRAJECTORY);
bool TRAJECTORY_IsBusy(TRAJECTORY_TypeDef* TRAJECTORY);
bool TRAJECTORY_MakeStep(TRAJECTORY_TypeDef* TRAJECTORY);

#endif
