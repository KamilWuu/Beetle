#include "setup.h"

void pinModes()
{
  
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(SERVO_LEFT,OUTPUT);
  pinMode(SERVO_RIGHT,OUTPUT);

  pinMode(MOTOR_LEFT_1,OUTPUT);
  pinMode(MOTOR_LEFT_2,OUTPUT);
  pinMode(MOTOR_RIGHT_1,OUTPUT);
  pinMode(MOTOR_RIGHT_2,OUTPUT);

  pinMode(XSHUT_TOF_1,OUTPUT);
  pinMode(XSHUT_TOF_2,OUTPUT);
  pinMode(XSHUT_TOF_3,OUTPUT);
  pinMode(XSHUT_TOF_4,OUTPUT);


  pinMode(GROUND_SENSOR_LEFT,INPUT);
  pinMode(GROUND_SENSOR_RIGHT,INPUT);

  pinMode(SWITCH_1, INPUT);
  pinMode(SWITCH_2, INPUT);

  pinMode(VOLTAGE, INPUT);
  pinMode(STARTER, INPUT);

}

