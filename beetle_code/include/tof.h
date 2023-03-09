
#include <Arduino.h>
#include "Wire.h"
#include "VL53L0X.h"


#define XSHUT_TOF_1 8
#define XSHUT_TOF_2 7
#define XSHUT_TOF_3 4
#define XSHUT_TOF_4 2

// DEFINE ADRESSES
#define TOF_1_ADDRESS 0x30 
#define TOF_2_ADDRESS 0x32
#define TOF_3_ADDRESS 0x34
#define TOF_4_ADDRESS 0x36

#define HIGH_SPEED
//#define HIGH_ACCURACY


#define DIST 200
#define TIMING_BUDGET 50


void setID();
void readFourSensors(uint16_t *tab);
void sensorsTest(uint16_t *tab);
