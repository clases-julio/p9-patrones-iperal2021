#include <iostream>
#include <string>
#include <cstdlib>
#include "Sensor.h"
#include "AirQuality.h"
using namespace std;

AirQuality::AirQuality() {}


void AirQuality::getData() {
    while (true) {
        int random = this->randomData();
        cout << "\n\t\tAir quality:\t\t" << (random + 30) << " ppm\n" << endl;
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