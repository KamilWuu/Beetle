#pragma once
#include "state.h"

//tryby jazdy

void motorsForward(uint16_t L_pwm, uint16_t R_pwm);
void motorsForward();

void motorsBack(uint16_t L_pwm, uint16_t R_pwm);
void motorsBack();

void motorsLeftRotate();
void motorsRightRotate();

void motorsHardBrake();
void motorsTurnOff();
