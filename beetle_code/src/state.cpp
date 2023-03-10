#include "state.h"

state::state()
{   
    
    this->groundTab[0] = 0;
    this->groundTab[1] = 0;

    this->switchTab[0] = 0;
    this->switchTab[1] = 0;

    for(int i = 0; i < 4; i++)
    {
        this->distTab[i] = ZERO_DISTANCE;
    }

    this->starterState = 0;
}


void state::sensorsStateRead(tof tof_sensors)
{
    readGround();
    tof_sensors.readFourSensors(this->distTab);
    this->starterState = digitalRead(STARTER);

}


void state::readGround()
{
    if(analogRead(GROUND_SENSOR_RIGHT) < GROUND_BORDER)
    {
        this->groundTab[0] = 1;
    }
    else
    {
        this->groundTab[0] = 0;
    }

    if(analogRead(GROUND_SENSOR_LEFT) < GROUND_BORDER)
    {
        this->groundTab[0] = 1;
    }
    else
    {
        this->groundTab[0] = 0;
    }
}


void state::readSwitch()
{
    this->switchTab[0] = digitalRead(SWITCH_1);
    this->switchTab[1] = digitalRead(SWITCH_2);
}

bool state::readStarter()
{
    return this->starterState = digitalRead(STARTER);

}

void state::distSensorsTest()
{

  if(distTab[0] < DIST)
    {
      digitalWrite(13,HIGH); //RED
    }
    else
    {
      digitalWrite(13,LOW);
    }


    if(distTab[1] < DIST)
    {
      digitalWrite(12,HIGH); //BLUE
    }
    else
    {
      digitalWrite(12,LOW);
    }

    if(distTab[2] < DIST)
    {
      digitalWrite(11,HIGH); //SERVO_LEFT
    }
    else
    {
      digitalWrite(11,LOW);
    }

    if(distTab[3] < DIST)
    {
      digitalWrite(3,HIGH); //SERVO_RIGHT
    }
    else
    {
      digitalWrite(3,LOW);
    }

}