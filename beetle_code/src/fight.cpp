#include "fight.h"


void makeAMove(state states)
{

    if(blackOnGround(states)){

        switch (states.GetDSH())
        {
        case 0:             //else - czyli brak wykrycia mozna dac tu cos typu szukanie przeciwnika or idk
            /* code */
            break;

        case 1:             //L_S
            /* code */
            break;

        case 2:             //L_F
            /* code */
            break;

        case 3:             //R_F
            /* code */
            break;

        case 4:             //R_S
            /* code */      
            break;

        case 5:             //R_F & L_F // najwazniejszy case jazda do przodu, jakiegos PID tu czy cos
            /* code */
            break;

        case 6:             //L_S & L_F
            /* code */
            break;

        case 7:             //R_F & R_S
            /* code */
            break;

        case 8:             //L_S & L_F & R_F
            /* code */
            break;

        case 9:             //L_F & R_F & R_S
            /* code */
            break;

        case 10:            //R_S & L_S & L_F & R_F
            /* code */  //to musi byc uznawane jako blad lub wykrycie "bezpiecznej strefy" i przeciwnika jednoczesnie
            break;

        default:
             //nie powinno wystapic ale jesli tak to zignoruj
            break;
        }

    }
}

bool blackOnGround(state states)
{
    bool L_G, R_G;
    L_G = states.GetG(0);
    R_G = states.GetG(1);

    if(L_G == 0 && R_G == 0)
    {
        return true; // <-- nie ma bialej linii, można jechać! :)
    }
    else
    {   
        if(L_G == 1 && R_G == 1 ) // <-- biala linia na obydwu
        {
            //nie wiem co zrob
            
        }

        if(L_G == 0 && R_G == 1 ) // <-- biala linia po prawej
        {
            //skret w lewo
            
        }

        if(L_G == 1 && R_G == 0 ) // <-- biala linia po lewej
        {
            //skret w prawo
            
        }
        return false;
    }
}

