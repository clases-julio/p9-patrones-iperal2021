#include <iostream>
#include <string>
#include <cstdlib>
#include "Sensor.h"
#include "Humidity.h"
using namespace std;

Humidity::Humidity() {}


void Humidity::getData() {
    while (true) {
        int random = this->randomData();
        cout << "\n\t\tHumidity:\t\t" << (random + 30) << " g/m³\n" << endl;
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