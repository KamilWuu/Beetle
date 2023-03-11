#include "tof.h"



void tof::setID()
{
  digitalWrite(XSHUT_TOF_1,LOW);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  delay(10);

  digitalWrite(XSHUT_TOF_1,HIGH);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);
  //this->tofTab[] wszedzie
  tofTab[0].setTimeout(TIMEOUT_VALUE);
  tofTab[0].setAddress(TOF_1_ADDRESS);
  tofTab[0].init();
  delay(10);

  
  digitalWrite(XSHUT_TOF_2,HIGH);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  tofTab[1].setTimeout(TIMEOUT_VALUE); 
  tofTab[1].setAddress(TOF_2_ADDRESS);
  tofTab[1].init();
  delay(10);


  digitalWrite(XSHUT_TOF_3,HIGH);
  digitalWrite(XSHUT_TOF_4,LOW);

  tofTab[2].setTimeout(TIMEOUT_VALUE);
  tofTab[2].setAddress(TOF_3_ADDRESS);
  tofTab[2].init();
  delay(10);


  digitalWrite(XSHUT_TOF_4,HIGH);

  tofTab[3].setTimeout(TIMEOUT_VALUE);
  tofTab[3].setAddress(TOF_4_ADDRESS);
  tofTab[3].init();
  delay(10);

  

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  for(int i = 0; i < 4; i++)
  {
    this->tofTab[i].setMeasurementTimingBudget(TIMING_BUDGET);
  }
  
  
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  for(int i = 0; i < 4; i++)
  {
    tofTab[i].setMeasurementTimingBudget(200000);
  }
#endif



}


void tof::readFourSensors(uint16_t *tab)
{
    for(int i = 0; i < 4; i++)
    {
      tab[i] = this->tofTab[i].readRangeSingleMillimeters();
    }
    //tab[0] = ZERO_DISTANCE;
}


void tof::tofTest(uint16_t *tab)
{

  if(tab[0] < DIST)
    {
      digitalWrite(13,HIGH); //RED
    }
    else
    {
      digitalWrite(13,LOW);
    }


    if(tab[1] < DIST)
    {
      digitalWrite(12,HIGH); //BLUE
    }
    else
    {
      digitalWrite(12,LOW);
    }

    if(tab[2] < DIST)
    {
      digitalWrite(11,HIGH); //SERVO_LEFT
    }
    else
    {
      digitalWrite(11,LOW);
    }

    if(tab[3] < DIST)
    {
      digitalWrite(3,HIGH); //SERVO_RIGHT
    }
    else
    {
      digitalWrite(3,LOW);
    }

}

void tof::setOne()
{
  digitalWrite(XSHUT_TOF_1,LOW);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  digitalWrite(XSHUT_TOF_1,LOW);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,HIGH);
  //this->tofTab[] wszedzie
  tofTab[3].setTimeout(TIMEOUT_VALUE);
  tofTab[3].setAddress(TOF_4_ADDRESS);
  tofTab[3].init();
  delay(10);

}

uint16_t tof::readOne()
{
  return this->tofTab[0].readRangeSingleMillimeters();
}