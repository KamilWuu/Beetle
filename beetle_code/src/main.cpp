
#include <Arduino.h>
#include "state.h"
#include "tof.h"





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

 /*   while(analogRead(VOLTAGE) < MIN_VOLTAGE)
    {
      digitalWrite(LED_RED, HIGH);
      delay(250);
      digitalWrite(LED_RED, LOW);
      delay(1000);
    }
*/
    /*while(!(sensorsState.readStarter()))
    {
      digitalWrite(LED_BLUE, HIGH);
      sensorsState.readSwitch();
    }
    digitalWrite(LED_BLUE, LOW);*/

  for (;;)
  { 
    /*sensorsState.sensorsStateRead(tofs);
    sensorsState.distSensorsTest();*/
    

    delay(1);
    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}