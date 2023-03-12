
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
  
  while(!(sensorsState.readStarter()))
  {
    if(analogRead(VOLTAGE) < MIN_VOLTAGE) voltageBlink(250,1000);
    sensorsState.sensorsRead(tofs);
    sensorsState.distSensorsTest();
    

  }
  
  //rozloz skrzydla

  for (;;)
  { 

    sensorsState.sensorsRead(tofs);
    
    makeAMove(sensorsState);
    

    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}