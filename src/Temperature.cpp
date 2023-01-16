#include <iostream>
#include <string>
#include <cstdlib>
#include "Sensor.h"
#include "Temperature.h"
using namespace std;

Temperature::Temperature() {}


void Temperature::getData() {
    while (true) {
        int random = this->randomData();
        cout << "\n\t\tTemperature:\t\t" << (random + 20) << " ºC\n" << endl;
        cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
        cin >> this->back_1;
        switch (this->back_1) {
        
        case 0:
            return;
            break;
        
        default:
            
            cout << "Orden incorrecta" << endl;
            system("sleep 1");
            this->cabeceraSensor();
            break;
        }
    }
    
}