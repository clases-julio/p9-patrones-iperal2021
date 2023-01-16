/* ---------------------------
File: Sensor.cpp
Author: Iker Peral del Pino
Date: 23/11/2022
Goal: Sensor class wich all the different sensors inherit the methods from
---------------------------- */


#include <iostream>
#include <string>
#include <cstdlib>
#include "Sensor.h"
using namespace std;

Sensor::Sensor() {}


int back_1;

// Generate a random number
int Sensor::randomData() {
    srand(time(NULL));
    return rand()%10;
}


// Method that shows the sensor data an is used as template for all types of sensor
void Sensor::getData(int opcion) {
    
    if (opcion == 5) {
        while (true) {
            cout << "\n\t\tRGB camera:\t\t*imagen*\n" << endl;
            cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
            cin >> back_1;
            switch (back_1) {
        
            case 0:
                return;
                break;
            
            default:
                
                cout << "Orden incorrecta" << endl;
                system("sleep 1");
                cabeceraSensor();
                break;
            }
        }
    }  else if (opcion == 6) {
        while (true) {
            cout << "\n\t\tTermal camera:\t\t*imagen*\n" << endl;
            cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
            cin >> back_1;
            switch (back_1) {
        
            case 0:
                return;
                break;
            
            default:
                
                cout << "Orden incorrecta" << endl;
                system("sleep 1");
                cabeceraSensor();
                break;
            }
        }
    }
}

// Heading used in the sesnsors interface
void Sensor::cabeceraSensor() {
    system("clear");
    cout << "\x1b[32m                                                                                         \n"          
"          / /                          ||   / /                                                      \n"
"         / /          // ( )  ___      ||  / /  ___      ___      ___       __      ___      ___     \n"
"        / / //   / / // / / //   ) )   || / / //___) ) //   ) ) //   ) ) //   ) ) //   ) ) ((   ) )  \n"
"       / / //   / / // / / //   / /    ||/ / //       ((___/ / //   / / //   / / //   / /   \\ \\    \n"
" ((___/ / ((___( ( // / / ((___/ /     |  / ((____     //__   ((___( ( //   / / ((___/ / //   ) )    \n"
"                                                                                                     \n"
"                         //    / /                                                                   \n"
"            ___         //___ / / ( )     ( )  ___      ___                                          \n"
"          //___) )     / ___   / / /     / / //   ) ) ((   ) )                                       \n"   
"         //           //    / / / /     / / //   / /   \\ \\                                         \n"     
"        ((____       //    / / / / ((  / / ((___/ / //   ) )    \x1b[0m                            \n\n"
"---------------------------------------------------------------------------------------------------- \n" << endl;

}


