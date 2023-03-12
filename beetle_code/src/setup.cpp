#include "setup.h"

void pinModes() //trza na rejestry przepisać
{
  DDRB = 0b00111111;
  DDRD = 0b11111100;

}

bool VLEDState =HIGH;// initial state of LED // trzeba do wyjebac jakos bo lokalne :/ // te zmienne są do funkcji voltageBlink
long VrememberTime=0;// this is used by the code
void voltageBlink(uint16_t onT, uint16_t offT)
{

  if( VLEDState ==HIGH )
  {
      if( (millis()- VrememberTime) >= onT){   
      VLEDState = LOW;// change the state of LED
      VrememberTime=millis();// remember Current millis() time
      }
  }
  else
  {   
      if( (millis()- VrememberTime) >= offT){     
      VLEDState =HIGH;// change the state of LED
      VrememberTime=millis();// remember Current millis() time
      }
  }

  digitalWrite(LED_RED,VLEDState);
}

