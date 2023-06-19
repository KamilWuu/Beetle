#pragma once
#include <Arduino.h>


//----LEDS----//
#define LED_RED 13 //PB5
#define LED_BLUE 12 //PB4

//----MOTORS----//
#define MOTOR_LEFT_FORWARD 10 //PB2
#define MOTOR_LEFT_BACK 9  //PB1

#define MOTOR_RIGHT_FORWARD 6 //PD6
#define MOTOR_RIGHT_BACK 5 //PD5

//----SERVOS----//
#define SERVO_LEFT 11 //PB3
#define SERVO_RIGHT 3 //PD3

//----TOF_XSHUTS----//
#define XSHUT_TOF_1 8 //PB0
#define XSHUT_TOF_2 7 //PD7
#define XSHUT_TOF_3 4 //PD4
#define XSHUT_TOF_4 2 //PD2

//----GROUND_SENSORS----//
#define GROUND_SENSOR_LEFT A7
#define GROUND_SENSOR_RIGHT A6

//----SWITCHES----//
#define SWITCH_1 A0
#define SWITCH_2 A1

//----STARTER----//
#define STARTER A3

//----VOLTAGE_MEASUREMENT----//
#define VOLTAGE A2
#define MIN_VOLTAGE 780 // x = 7,5 (minimal) * 10/20,,, 1023*x/5 = 770

void pinModes();
void voltageBlink(uint16_t onT, uint16_t offT);