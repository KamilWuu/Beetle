#include <Arduino.h>
#include "setup.h"
#include "tof.h"


int *tablica;

void setup() {
  // pinModes:
   //----LEDS----//
   pinMode(LED_RED, OUTPUT);
   pinMode(LED_BLUE, OUTPUT);

   //----MOTORS----//
   pinMode(MOTOR_LEFT_1, OUTPUT);
   pinMode(MOTOR_LEFT_2, OUTPUT);
   pinMode(MOTOR_RIGHT_1, OUTPUT);
   pinMode(MOTOR_RIGHT_2, OUTPUT);

   //----SERVOS----//
   pinMode(SERVO_LEFT, OUTPUT);
   pinMode(SERVO_RIGHT, OUTPUT);

   //----TOF_SENSORS_PINS----//
   pinMode(XSHUT_TOF_1, OUTPUT);
   pinMode(XSHUT_TOF_2, OUTPUT);
   pinMode(XSHUT_TOF_3, OUTPUT);
   pinMode(XSHUT_TOF_4, OUTPUT);

   //----GROUND_SENSORS----//
  pinMode(GROUND_SENSOR_LEFT, INPUT);
   pinMode(GROUND_SENSOR_RIGHT, INPUT);

   //----SWITCHES----//
   pinMode(SWITCH_1, INPUT);
   pinMode(SWITCH_2, INPUT);

   //----VOLTAGE_MEASUREMENT----//
   pinMode(VOLTAGE, INPUT);

   //----STARTER----//
   pinMode(STARTER, INPUT);


  setID();
 
}

void loop() {

  tablica = read_four_sensors();                //< -- do tego mozna sie odnosić jak do normalnej tablicy
  delay(100);


}
