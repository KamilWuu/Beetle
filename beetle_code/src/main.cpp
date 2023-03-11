
#include <Arduino.h>
#include "state.h"
#include "tof.h"
#include "fight.h"

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
  


  pinModes();
  Wire.begin();
  tofs.setID();
  

  while(analogRead(VOLTAGE) < MIN_VOLTAGE)
  {
    digitalWrite(LED_RED, HIGH);
    delay(250);
    digitalWrite(LED_RED, LOW);
    delay(1000);
  }

  while(!(sensorsState.readStarter()))
  {
    digitalWrite(LED_BLUE, HIGH);
    sensorsState.readSwitch();
  }
  digitalWrite(LED_BLUE, LOW);
  //serwa w dol

  while(digitalRead(SWITCH_1) == 1)
  {
    digitalWrite(LED_BLUE, HIGH);
    
  }
  digitalWrite(LED_BLUE, LOW);
  

  //distTab[0] = PRAWY_bok
  //distTab[1] - lewy bok
  //distab[2] - lewy przod
  //disTab[3]  - prawy przod


  

  for (;;)
  { 

    sensorsState.sensorsStateRead(tofs);
    takeDecision(sensorsState);
    

    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}