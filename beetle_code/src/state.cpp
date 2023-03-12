#include "state.h"


  
    #define R_S distTab[0]
    #define L_S  distTab[1]
    #define L_F  distTab[2]
    #define R_F  distTab[3]

    //R_S,L_S,L_F,R_F; // distances PRAWY_BOK, LEWY_BOK, LEWY_PRZOD, PRAWY_PRZOD

state::state()
{   
    
    this->groundTab[0] = 0;
    this->groundTab[1] = 0;

    this->switchTab[0] = 0;
    this->switchTab[1] = 0;

    for(int i = 0; i < 4; i++)
    {
        this->distTab[i] = ZERO_DISTANCE;
        this->LastDistTab[i] = ZERO_DISTANCE;
    }

    this->starterState = 0;
    this->distStateHolder = 0;
}


void state::sensorsRead(tof tof_sensors)
{
    for(int i = 0; i < 4; i++){this->LastDistTab[i] = this->distTab[i];} // zapamietanie poprzednich pomiarów
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



void state::distState() //Ustawienie "flagi" z tofow, patrz plik: "dist_State_Cases.png"
{
     //R_S,L_S,L_F,R_F; // distances PRAWY_BOK, LEWY_BOK, LEWY_PRZOD, PRAWY_PRZOD

    if(R_S < DIST_BORDER && L_S < DIST_BORDER && L_F < DIST_BORDER && R_F < DIST_BORDER) /*wszedzie this->*/distStateHolder = 10;

    else if(L_F < DIST_BORDER && R_F < DIST_BORDER && R_S < DIST_BORDER) distStateHolder = 9;
    else if(L_S < DIST_BORDER && L_F < DIST_BORDER && R_F < DIST_BORDER) distStateHolder = 8;

    else if(R_F < DIST_BORDER && R_S < DIST_BORDER ) distStateHolder = 7;
    else if(L_S < DIST_BORDER && L_F< DIST_BORDER) distStateHolder = 6;
    
    else if(R_F < DIST_BORDER && L_F < DIST_BORDER) distStateHolder = 5; //jazda do przodu

    else if(R_S < DIST_BORDER) distStateHolder = 4;
    else if(R_F < DIST_BORDER) distStateHolder = 3;
    else if(L_F < DIST_BORDER) distStateHolder = 2;
    else if(L_S < DIST_BORDER) distStateHolder = 1;
    else distStateHolder = 0;
}

void state::distSensorsTest()
{
  if(L_F < DIST_BORDER && R_F < DIST_BORDER)
  {
    digitalWrite(LED_BLUE,HIGH);
    digitalWrite(LED_RED,HIGH);
  }
  else if(L_F < DIST_BORDER)
  {
    digitalWrite(LED_BLUE,HIGH);
    digitalWrite(LED_RED,LOW);
  }
  else if(R_F < DIST_BORDER)
  {
    digitalWrite(LED_BLUE,LOW);
    digitalWrite(LED_RED,HIGH);
  }
  else
  {
    digitalWrite(LED_BLUE,LOW);
    digitalWrite(LED_RED,LOW);
  }
}

void state::distSensorsTest2()
{

  if(R_S < DIST)
    {
      digitalWrite(13,HIGH); //RED
    }
    else
    {
      digitalWrite(13,LOW);
    }


    if(L_S < DIST)
    {
      digitalWrite(12,HIGH); //BLUE
    }
    else
    {
      digitalWrite(12,LOW);
    }

    if(L_F < DIST)
    {
      digitalWrite(11,HIGH); //SERVO_LEFT
    }
    else
    {
      digitalWrite(11,LOW);
    }

    if(R_F < DIST)
    {
      digitalWrite(3,HIGH); //SERVO_RIGHT
    }
    else
    {
      digitalWrite(3,LOW);
    }

}
