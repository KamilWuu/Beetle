#include "tof.h"



Adafruit_VL53L0X tof1 = Adafruit_VL53L0X();  //lox1
Adafruit_VL53L0X tof2 = Adafruit_VL53L0X();
Adafruit_VL53L0X tof3 = Adafruit_VL53L0X();
Adafruit_VL53L0X tof4 = Adafruit_VL53L0X();

VL53L0X_RangingMeasurementData_t maesures[4];

void setID() {
  // all reset
  digitalWrite(XSHUT_TOF_1, LOW);    
  digitalWrite(XSHUT_TOF_2, LOW);    
  digitalWrite(XSHUT_TOF_3, LOW);    
  digitalWrite(XSHUT_TOF_4, LOW);    
  delay(10);
  // all unreset
  digitalWrite(XSHUT_TOF_1, HIGH);  
  digitalWrite(XSHUT_TOF_2, HIGH);  
  digitalWrite(XSHUT_TOF_3, HIGH);  
  digitalWrite(XSHUT_TOF_4, HIGH);  
  delay(10);

  // activating LOX1 and resetting TOF2, 3 and 4
  digitalWrite(XSHUT_TOF_1, HIGH);
  digitalWrite(XSHUT_TOF_2, LOW);
  digitalWrite(XSHUT_TOF_3, LOW);
  digitalWrite(XSHUT_TOF_4, LOW);
  // initing LOX1

  if(!tof1.begin(TOF_1_ADDRESS)) {
    //Serial.println(F("Failed to boot first VL53L0X"));
    while(1);
  }
  delay(10);


  // activating LOX2 
  digitalWrite(XSHUT_TOF_2, HIGH);
  digitalWrite(XSHUT_TOF_3, LOW);
  digitalWrite(XSHUT_TOF_4, LOW);
  // initing LOX2

  if(!tof2.begin(TOF_2_ADDRESS)) {
    //Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }
  delay(10);

  // activating LOX3
  digitalWrite(XSHUT_TOF_3, HIGH);
  digitalWrite(XSHUT_TOF_4, LOW);
  // initing LOX3

  if(!tof3.begin(TOF_3_ADDRESS)) {
    //Serial.println(F("Failed to boot third VL53L0X"));
    while(1);
  }
  delay(10);

  // activating LOX4
  digitalWrite(XSHUT_TOF_4, HIGH);
  // initing LOX4

  if(!tof4.begin(TOF_4_ADDRESS)) {
    //Serial.println(F("Failed to boot fourth VL53L0X"));
    while(1);
  }
  delay(10);



  
}

int * read_four_sensors() { // napisac funkcje ktora zwraca tablice wartosci z czujnikow od lewej strony, jesli bylo by out of range to zwracalo by 0 lub -1 = false, jesli cos wykryl zwraca wartosc wtedy ten if jest true = (if(pomiar.RangeStatus !=4)))
  
    static int tabOfDist[4];

    for(uint8_t i = 0; i < 4; i++ )
    {
        if(maesures[i].RangeStatus != 4)  // if not out of range
        {
            tabOfDist[i] = maesures[i].RangeMilliMeter;
        }
        else
        {
            tabOfDist[i] = N_VALUE;
        }
    }
    return tabOfDist;
}