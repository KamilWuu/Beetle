#include "tof.h"
VL53L0X tof1;
VL53L0X tof2;
VL53L0X tof3;
VL53L0X tof4;
  


void setID()
{
  pinMode(XSHUT_TOF_1,OUTPUT);
  pinMode(XSHUT_TOF_2,OUTPUT);
  pinMode(XSHUT_TOF_3,OUTPUT);
  pinMode(XSHUT_TOF_4,OUTPUT);

  Wire.begin();


  digitalWrite(XSHUT_TOF_1,LOW);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  delay(10);

  digitalWrite(XSHUT_TOF_1,HIGH);
  digitalWrite(XSHUT_TOF_2,LOW);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  tof1.setTimeout(500);
  tof1.setAddress(TOF_1_ADDRESS);
  tof1.init();
  delay(10);

  
  digitalWrite(XSHUT_TOF_2,HIGH);
  digitalWrite(XSHUT_TOF_3,LOW);
  digitalWrite(XSHUT_TOF_4,LOW);

  tof2.setTimeout(500); 
  tof2.setAddress(TOF_2_ADDRESS);
  tof2.init();
  delay(10);


  digitalWrite(XSHUT_TOF_3,HIGH);
  digitalWrite(XSHUT_TOF_4,LOW);

  tof3.setTimeout(500);
  tof3.setAddress(TOF_3_ADDRESS);
  tof3.init();
  delay(10);


  digitalWrite(XSHUT_TOF_4,HIGH);

  tof4.setTimeout(500);
  tof4.setAddress(TOF_4_ADDRESS);
  tof4.init();
  delay(10);

  digitalWrite(XSHUT_TOF_1,HIGH);
  digitalWrite(XSHUT_TOF_2,HIGH);
  digitalWrite(XSHUT_TOF_3,HIGH);
  digitalWrite(XSHUT_TOF_4,HIGH);

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  tof1.setMeasurementTimingBudget(TIMING_BUDGET);
  tof2.setMeasurementTimingBudget(TIMING_BUDGET);
  tof3.setMeasurementTimingBudget(TIMING_BUDGET);
  tof4.setMeasurementTimingBudget(TIMING_BUDGET);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  tof1.setMeasurementTimingBudget(200000);
  tof2.setMeasurementTimingBudget(200000);
  tof3.setMeasurementTimingBudget(200000);
  tof4.setMeasurementTimingBudget(200000);
#endif



}


void readFourSensors(uint16_t *tab)
{
    tab[0] = 3333;
    tab[1] = tof2.readRangeSingleMillimeters();
    tab[2] = tof3.readRangeSingleMillimeters();
    tab[3] = tof4.readRangeSingleMillimeters();
}


void sensorsTest(uint16_t *tab)
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