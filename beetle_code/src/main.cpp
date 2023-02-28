#include "setup.h"


int main(void)
{
  /////////Arduino stuff//////////
  init();
#if defined(USBCON)
  USBDevice.attach();
#endif
  ////////////////////////////////
    //setup() here:
	
//pinModes:
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
pinMode(TOF_PIN_1, OUTPUT);
pinMode(TOF_PIN_2, OUTPUT);
pinMode(TOF_PIN_3, OUTPUT);
pinMode(TOF_PIN_4, OUTPUT);

//----GROUND_SENSORS----//
pinMode(GROUND_SENSOR_LEFT, INPUT);
pinMode(GROUND_SENSOR_RIGHT, INPUT);

//----SWITCHES----//
pinMode(SWITCH_2, INPUT);
pinMode(SWITCH_3, INPUT);

//----VOLTAGE_MEASUREMENT----//
pinMode(VOLTAGE, INPUT);

//----STARTER----//
pinMode(STARTER, INPUT);

  for (;;)
  { // void loop() equivalent
    
    digitalWrite(LED_RED, HIGH);
    delay(100);
    digitalWrite(LED_RED, LOW);
    delay(100);
    ////////////Arduino stuff/////////////
    if (serialEventRun)
      serialEventRun();
    //////////////////////////////////////
  }
  return 0;
}