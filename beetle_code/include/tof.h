#pragma once
#include <Arduino.h>
#include "Wire.h"
#include "VL53L0X.h"
#include "setup.h"

// DEFINE ADRESSES
#define TOF_1_ADDRESS 0x52 
#define TOF_2_ADDRESS 0x54
#define TOF_3_ADDRESS 0x56
#define TOF_4_ADDRESS 0x51

#define HIGH_SPEED
//#define HIGH_ACCURACY

#define TIMING_BUDGET 150
#define TIMEOUT_VALUE 100

#define ZERO_DISTANCE 2048
#define DIST 200


class tof
{
VL53L0X tofTab[4]; 

public:

void setID();
void readFourSensors(uint16_t *tab);
/*void tofTest(uint16_t *tab);
uint16_t readOne();
void setOne();*/
};


