#ifndef PID_H
#define PID_H
#include "main.h"

extern int q;

typedef struct {
    float target;
    float target_angle;
    float current_angle;

    float Kp;
    float Ki;
    float Kd;

    float ek;
    float ek1;
    float ek2;

    float sum;
} struct_pid_t;

float PID_Loc(float set_value, float actual_value, struct_pid_t *pid);
struct_pid_t pid_init(float Kp, float Ki, float Kd);
void motor_speed_control(int16_t target_speed);
int motor_angle_control(int16_t target_angle);

#endif

