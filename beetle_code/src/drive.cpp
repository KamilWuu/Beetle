#include "drive.h"


void motorsForward(uint16_t L_pwm, uint16_t R_pwm)
{
    analogWrite(MOTOR_LEFT_FORWARD, L_pwm);
    analogWrite(MOTOR_RIGHT_FORWARD, R_pwm);
}

void motorsForward()
{
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
}

void motorsBack(uint16_t L_pwm, uint16_t R_pwm)
{
    analogWrite(MOTOR_LEFT_BACK, L_pwm);
    analogWrite(MOTOR_RIGHT_BACK, R_pwm);
}

void motorsBack()
{   
    digitalWrite(MOTOR_LEFT_BACK, HIGH);
    digitalWrite(MOTOR_RIGHT_BACK, HIGH);
}

void motorsLeftRotate()
{
    digitalWrite(MOTOR_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_RIGHT_BACK, LOW);
    digitalWrite(MOTOR_LEFT_BACK, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
}

void motorsRightRotate()
{
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_BACK, HIGH);
}


void motorsHardBrake()
{
    digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
    digitalWrite(MOTOR_LEFT_BACK, HIGH);
    digitalWrite(MOTOR_RIGHT_BACK, HIGH);
}

void motorsTurnOff()
{
    digitalWrite(MOTOR_LEFT_FORWARD, 0);
    digitalWrite(MOTOR_RIGHT_FORWARD, 0);
    digitalWrite(MOTOR_LEFT_BACK, 0);
    digitalWrite(MOTOR_RIGHT_BACK, 0);
}