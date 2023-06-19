
#include <Arduino.h>
#include "state.h"
#include "tof.h"
#include "fight.h"
#include "Servo.h"

#define LEFT_PWM_VALUE 150
#define RIGHT_PWM_VALUE 150

#define LEFT_PWM_MAX 255
#define RIGHT_PWM_MAX 255





int main(void)
{
  /////////Arduino stuff//////////
  init();
#if defined(USBCON)
  USBDevice.attach();
#endif
  ////////////////////////////////
  //SETUP
  state sensorsState;
  tof tofs;
  Servo servoLeft, servoRight; 
  pinModes();
  Wire.begin();
  tofs.setID();
  
  /*servoLeft.attach(SERVO_LEFT);
  servoRight.attach(SERVO_RIGHT);*/

  servoLeft.write(POSL0);
  servoRight.write(POSR0);

  for(int i = 0; i > 5; i++)
  {

  digitalWrite(LED_BLUE,HIGH);
  digitalWrite(LED_RED, LOW);
  delay(100);
  digitalWrite(LED_BLUE,LOW);
  digitalWrite(LED_RED, HIGH);
  delay(100);
  }

  while(!(sensorsState.readStarter()))
  {
    //if(analogRead(VOLTAGE) < MIN_VOLTAGE) voltageBlink(250,1000);
    sensorsState.sensorsRead(tofs);
    sensorsState.distSensorsTest();
    
  }
  
  //digitalWrite(LED_BLUE, HIGH);
  servoLeft.write(POSL1);
  servoRight.write(POSR1);

  
for(;;)
{
  while (sensorsState.readStarter())
  { 
    sensorsState.sensorsRead(tofs);
    makeAMove(sensorsState, tofs, servoLeft, servoRight);
    sensorsState.distSensorsTest();
  }
  motorsTurnOff();
    digitalWrite(LED_RED,HIGH);
    digitalWrite(LED_BLUE,LOW);
    delay(300);
    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_BLUE,HIGH);
    delay(300);
    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}