#include <iostream>
#include <string>
#include <cstdlib>
#include "Sensor.h"
#include "Brightness.h"
using namespace std;

Brightness::Brightness() {}


void Brightness::getData() {
    while (true) {
        int random = this->randomData();
        cout << "\n\t\tBrightness:\t\t" << (random + 10) << " lmen/m²\n" << endl;
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