#pragma once
#include <Arduino.h>

#include "Adafruit_VL53L0X.h"

#define N_VALUE 2137

//----TOF_SENSORS_PINS----//
#define XSHUT_TOF_1 8
#define XSHUT_TOF_2 7
#define XSHUT_TOF_3 4
#define XSHUT_TOF_4 2

//DEFINE ADRESSES
#define TOF_1_ADDRESS 0x20  // LOX1_ADDRESS
#define TOF_2_ADDRESS 0x22
#define TOF_3_ADDRESS 0x24
#define TOF_4_ADDRESS 0x26

void setID();
int * read_four_sensors();
