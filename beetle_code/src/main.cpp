
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
  uint16_t tablica[4];
  
  for (;;)
  { //LOOP

  readFourSensors(tablica);
  sensorsTest(tablica);
    

    delay(1);
    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}