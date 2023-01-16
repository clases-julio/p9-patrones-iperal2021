/* ---------------------------
File: Security.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: Security class with security functions
---------------------------- */

// Nedeed libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include "Security.h"
#include "Dashboard.h"
using namespace std;


string seguridad;
string open;
string alarm_status = "encendido";
int entrada;

int back;

Security::Security() {}

Dashboard db;

// Depend on the reequested action a different method is call
void Security::security(string seguridad) {
    if (seguridad == "puertas") {
        door();
    } else if (seguridad == "ventanas") {
        window();
    } else if (seguridad == "camaras") {
        camera();
    } else if (seguridad == "alarma") {
        alarm();
    }
}

// This method show the doors whith their ID and status
void Security::door() {
    while (true) {
        open_close();
        cout << "Puerta: 01\tLocalización: Huerto\tEstado: " << open << endl;
        open_close();
        cout << "Puerta: 02\tLocalización: Almacen\tEstado: " << open << endl;
        open_close();
        cout << "Puerta: 03\tLocalización: Despacho\tEstado: " << open << endl;
        cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
        cout << ">>> ";
        cin >> back;

        // If an order different of 0 is inserted, the door menu is restarted.
        switch (back) {
        
        case 0:
            return;
            break;
        
        default:
            
            cout << "Orden incorrecta" << endl;
            system("sleep 1");
            db.cabecera();
            break;
        }
    }
}    

// This method show the window information
void Security::window() {
    while (true) {
        open_close();
        cout << "Ventana: 01\tLocalización: Huerto\tEstado: " << open << endl;
        open_close();
        cout << "Ventana: 02\tLocalización: Almacen\tEstado: " << open << endl;
        open_close();
        cout << "Ventana: 03\tLocalización: Despacho\tEstado: " << open << endl;
        cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
        cin >> back;
        // if an order different of 0 the programm restart
        switch (back) {
        
        case 0:
            return;
            break;
        
        default:
            
            cout << "Orden incorrecta" << endl;
            system("sleep 1");
            db.cabecera();
            break;
        }
    }
}

// This method show the security camera imagen
void Security::camera() {
    while (true) {
        cout << "Imagina que hay una camara" << endl;
        cout << "\n\t\tPara volver atrás introduzca 0 + ENTER" << endl;
        cin >> back;
        switch (back) {
        case 0:
            return;
            break;
        default:
            cout << "Orden incorrecta" << endl;
            system("sleep 1");
            db.cabecera();
            break;
        }
    }
}
// The method shows the alarm status and allow the user to turn it on or off
void Security::alarm() {
    while (true) {
        cout << "\n\tAlarma: " << alarm_status << "\n\n" << endl;
        cout << "Para encender introduzca 1, para apagar introduzca 2, para salir 0\n" << endl;
        cout << ">>> ";
        cin >> entrada;
        switch (entrada) {
        
        case 0:
            return;

        case 1:
            alarm_status = "encendido";
            db.cabecera();
            break;

        case 2:
            alarm_status = "apagado";
            db.cabecera();
            break;
        default:
            cout << "Orden incorrecta" << endl;
            system("sleep 1");
            db.cabecera();
            break;
        }
    }
}

// Method to generate random number
int Security::generate_random() {
    srand(time(NULL));
    return rand()%10;
}

// Using the random number generator a variable get value open or close
void Security::open_close() {
    int random = generate_random();
    if (random >= 0 && random <= 4) {
        open = "close";
    } else {
        open = "open";
    }
}
