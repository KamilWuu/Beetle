#include "fight.h"


uint16_t takeDecision(state states)
{
    uint16_t R_S,L_S,L_F,R_F; // distances PRAWY_BOK, LEWY_BOK, LEWY_PRZOD, PRAWY_PRZOD

    R_S = states.GetD(0);
    L_S = states.GetD(1);
    L_F = states.GetD(2);
    R_F = states.GetD(3);


    if(R_S < DIST_BORDER && L_S < DIST_BORDER && L_F < DIST_BORDER && R_F < DIST_BORDER) return 10;

    else if(L_F < DIST_BORDER && R_F < DIST_BORDER && R_S < DIST_BORDER) return 9;
    else if(L_S < DIST_BORDER && L_F < DIST_BORDER && R_F < DIST_BORDER) return 8;

    else if(R_F < DIST_BORDER && R_S < DIST_BORDER ) return 7;
    else if(L_S < DIST_BORDER && L_F< DIST_BORDER) return 6;
    
    else if(R_F < DIST_BORDER && L_F < DIST_BORDER) return 5; //jazda do przodu

    else if(R_F < DIST_BORDER) return 4;
    else if(R_F < DIST_BORDER) return 3;
    else if(L_F < DIST_BORDER) return 2;
    else if(L_S < DIST_BORDER) return 1;
    else return 0;
}

void case1()
{

}

void case2()
{

}
//...