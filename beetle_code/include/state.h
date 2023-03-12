#pragma once
#include <Arduino.h>
#include "tof.h"


#define GROUND_BORDER 500
#define DIST_BORDER 255

class state
{
    uint16_t distTab[4];    //indeks: 0 = PRAWY_bok, 1 - lewy bok,  2 - lewy przod, 3  - prawy przod
    uint16_t lastDistTab[4];    //indeks: 0 = PRAWY_bok, 1 - lewy bok,  2 - lewy przod, 3  - prawy przod
    bool groundTab[2];      //indeks: 0 - PRAWY, 1 -LEWY //bool: 1 = biala linia, 0 = brak bialej linii
    bool switchTab[2];  
    bool starterState;
    uint16_t distStateHolder;   //schowek na flage z tofow, patrz plik: "dist_State_Cases.png"
public:
    
    

    state();
    //~state();
    
    void sensorsRead(tof tof_sensors);
    void readGround();  
    void readSwitch();
    bool readStarter();  
    void distSensorsTest2();
    void distSensorsTest();

    void distState();   //Ustawienie "flagi" z tofow, patrz plik: "dist_State_Cases.png"

    uint16_t GetD(int index){return distTab[index];};
    bool GetG(int index){return groundTab[index];};
    bool GetSW(int index){return groundTab[index];};
    bool GetST(){return starterState;};
    uint16_t GetDSH(){return distStateHolder;};
};

  //distTab[0] = PRAWY_bok
  //distTab[1] - lewy bok
  //distab[2] - lewy przod
  //disTab[3]  - prawy przod
