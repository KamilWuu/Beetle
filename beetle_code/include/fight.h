#pragma once
#include "setup.h"
#include "state.h"
#include "drive.h"
#include "Servo.h"

#define PWM_MAX 255
#define TIME_OF_WHITE_ROT 500
#define TIME_OF_ATTACK_ROT 500
#define TIME_OF_SEARCH_ROT 500

#define POSL0 0
#define POSL1 90
#define POSL2 180

#define POSR0 180
#define POSR1 90
#define POSR2 0

void makeAMove(state states, tof tofs, Servo& servoLeft, Servo& servoRight);
bool blackOnGround(state states, tof tofs, Servo& servoLeft, Servo& servoRight);