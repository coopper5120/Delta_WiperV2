#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

int delta_calcAngleYZ(float x0, float y0, float z0, float* theta);
int delta_calcInverse(float x0, float y0, float z0, float* theta1, float* theta2, float* theta3);
int delta_calcForward(float theta1, float theta2, float theta3, float* x0, float* y0, float* z0);

#endif
