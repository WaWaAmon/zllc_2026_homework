#include "pid.h"
#include "CAN_receive.h"
#include "main.h"
#include <math.h>

extern struct_pid_t chassis_pid[4];

float PID_Loc(float set_value, float actual_value, struct_pid_t *pid) {
    float pid_loc;

    pid->ek = set_value - actual_value;
    pid->sum += pid->ek;

    if (pid->sum > 1000.0f) {
        pid->sum = 1000.0f;
    } else if (pid->sum < -1000.0f) {
        pid->sum = -1000.0f;
    }

    pid_loc = pid->Kp * (pid->ek) + pid->Ki * pid->sum + pid->Kd * (pid->ek - pid->ek1);
    pid->ek2 = pid->ek1;
    pid->ek1 = pid->ek;

    return pid_loc;
}

struct_pid_t pid_init(float Kp, float Ki, float Kd) {
    struct_pid_t pid;

    pid.Kp = Kp;
    pid.Ki = Ki;
    pid.Kd = Kd;

    pid.ek = 0.0f;
    pid.ek1 = 0.0f;
    pid.ek2 = 0.0f;

    pid.sum = 0.0f;

    return pid;
}

void motor_speed_control(int16_t target_speed) {
    const motor_measure_t *motor_measure = get_chassis_motor_measure_point(0);
    chassis_pid[0].target = (float)target_speed;
    float current_speed = motor_measure->speed_rpm;

    float control_output = PID_Loc((float)target_speed, current_speed, &chassis_pid[0]);

    CAN_cmd_chassis((int16_t)control_output, 0, 0, 0);
}

int motor_angle_control(int16_t target_angle) {
    const motor_measure_t *motor_measure = get_chassis_motor_measure_point(0);
    chassis_pid[0].target_angle = (float)target_angle;

    float current_angle = ((float)(motor_measure->ecd) / 8192.0f * 360.0f + q * 360.0f) * (187.0f / 3591.0f);
    chassis_pid[0].current_angle = (float)current_angle;
    float control_output = PID_Loc((float)target_angle, current_angle, &chassis_pid[1]);

    motor_speed_control((int16_t)control_output);

    return 0;
}

