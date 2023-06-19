#include "fight.h"


void makeAMove(state states, tof tofs, Servo &servoLeft, Servo &servoRight)
{
    uint16_t L_pwm, R_pwm;
    uint16_t L_dist, R_dist, L_LastDist, R_LastDist;
    uint16_t L_S_dist, R_S_dist, L_S_LastDist, R_S_LastDist; //<-- S oznacza bok
    uint16_t time0, time1;
    uint16_t  randomNumber;

    L_dist = states.GetD(3);
    R_dist = states.GetD(2);
    L_S_dist = states.GetD(1);
    R_S_dist = states.GetD(0);

    L_LastDist = states.GetLD(3);
    R_LastDist = states.GetLD(2);
    L_S_LastDist = states.GetLD(1);
    R_S_LastDist = states.GetLD(0);

    if (blackOnGround(states, tofs, servoLeft, servoRight))
    {

        switch (states.GetDSH())
        {
        case 0: // else - czyli brak wykrycia mozna dac tu cos typu szukanie przeciwnika or idk
            time0 = millis();
            randomNumber = random(3); // losowanie reakcji
            while (randomNumber == 0 && (states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT) && blackOnGround(states, tofs, servoLeft, servoRight) == true)
            {
                states.sensorsRead(tofs);
                motorsForward(0, PWM_MAX);
            } // reakcja skret w lewo
            while (randomNumber == 1 && (states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT) && blackOnGround(states, tofs, servoLeft, servoRight) == true)
            {
                states.sensorsRead(tofs);
                motorsForward(PWM_MAX, 0);
            }// reakcja skret w prawo
            while (randomNumber == 2 && (states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT) && blackOnGround(states, tofs, servoLeft, servoRight) == true)
            {
                states.sensorsRead(tofs);
                motorsForward(PWM_MAX, PWM_MAX);
            }// reakcja prosto
            break;

        case 1: // L_S
            time1 = millis();
            while (states.GetDSH() == 0 && states.GetDSH() == 1 && millis() - time1 < TIME_OF_SEARCH_ROT)
            {
                L_pwm = constrain((L_S_dist/* + L_S_LastDist + L_pwm  3*/), 0, 255);
                R_pwm = PWM_MAX;
                states.sensorsRead(tofs);
                motorsForward(L_pwm, R_pwm);
            }
            break;

        case 2: // L_F

            L_pwm = constrain((L_dist/* + L_LastDist + L_pwm / 3*/), 0, 255);
            R_pwm = PWM_MAX;
            motorsForward(L_pwm, R_pwm);
            break;

        case 3: // R_F

            L_pwm = PWM_MAX;
            R_pwm = constrain((R_dist/* + R_LastDist + R_pwm / 3*/), 0, 255);
            motorsForward(L_pwm, R_pwm);
            break;

        case 4: // R_S
            time1 = millis();
            while (states.GetDSH() == 0 && states.GetDSH() == 4 && millis() - time1 < TIME_OF_SEARCH_ROT)
            {
                L_pwm = PWM_MAX;
                R_pwm = constrain((R_S_dist/* + R_S_LastDist + R_pwm / 3*/), 0, 255);
                states.sensorsRead(tofs);
                motorsForward(L_pwm, R_pwm);
            }
            break;

        case 5: // R_F & L_F // najwazniejszy case jazda do przodu, jakiegos PID tu czy cos //PIZDA do przodu a nie pid!
            motorsForward(PWM_MAX, PWM_MAX);
            break;

       //case 6: // L_S & L_F
       //    // moze wyciągać srednią miedzy L_S A L_F i wrzucać na PWM?
       //    break;

       //case 7: // R_F & R_S
       //    /* code */
       //    break;

       //case 8: // L_S & L_F & R_F
       //        // tutaj mozna jakos polaczyc roznice pwmu miedzy R a L
       //    /* code */
       //    break;

       //case 9: // L_F & R_F & R_S
       //    /* code */
       //    break;

       //case 10:       // R_S & L_S & L_F & R_F
       //    /* code */ // to musi byc uznawane jako blad lub wykrycie "bezpiecznej strefy" i przeciwnika jednoczesnie
       //    break;

        default:
            // nie powinno wystapic ale jesli tak to zignoruj
            break;
        }
    }
}

bool blackOnGround(state states, tof tofs, Servo &servoLeft, Servo &servoRight)
{
    bool L_G, R_G;
    uint16_t time0;
    L_G = states.GetG(0);
    R_G = states.GetG(1);

    if (L_G == 0 && R_G == 0)
    {
        return true; // <-- nie ma bialej linii, można jechać! :)
    }
    else
    {
        if (L_G == 1 && R_G == 1) // <-- biala linia na obydwu
        {
            motorsHardBrake();
            time0 = millis();
            servoLeft.write(POSL2);
            servoRight.write(POSR2);
            while((states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT) )
            {
                states.sensorsRead(tofs);
                motorsLeftRotate();
            }
            servoLeft.write(POSL1);
            servoRight.write(POSR1);
            digitalWrite(MOTOR_LEFT_BACK, LOW);
        }
        

        if (L_G == 0 && R_G == 1) // <-- biala linia po prawej
        {
            motorsHardBrake();
            time0 = millis();
            servoLeft.write(POSL2);
            servoRight.write(POSR2);
            while ((states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT))
            {
                states.sensorsRead(tofs);
                motorsForward(0, PWM_MAX);
            }
            servoLeft.write(POSL1);
            servoRight.write(POSR1);
        }

        if (L_G == 1 && R_G == 0) // <-- biala linia po lewej
        {
            motorsHardBrake();
            time0 = millis();

            servoLeft.write(POSL2);
            servoRight.write(POSR2);

            while ((states.GetDSH() == 0) && (millis() - time0 < TIME_OF_WHITE_ROT))
            {
                states.sensorsRead(tofs);
                motorsForward(PWM_MAX, 0);
            }
            servoLeft.write(POSL1);
            servoRight.write(POSR1);
        }
        return false;
    }
}
