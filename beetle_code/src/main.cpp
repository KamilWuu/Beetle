
#include <Arduino.h>
#include "setup.h"
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
  uint16_t pomiary[4];
  Wire.begin();
  setID();

  for (;;)
  { 
    readFourSensors(pomiary);
    sensorsTest(pomiary);
    delay(1);
    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}