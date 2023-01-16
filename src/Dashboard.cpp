/* ---------------------------
File: Dashboard.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: Menus used in the program
---------------------------- */

// Nedeed libraries
#include <iostream>
#include "Temperature.h"
#include "Humidity.h"
#include "Brightness.h"
#include "AirQuality.h"
#include "Security.h"
#include "Sensor.h"
#include "DataBase.h"
#include "Dashboard.h"
#include "main.h"
#include "Login.h"
#include "Exceptions.h"
using namespace std;

// Variable to save the option required
int opcion;


Dashboard::Dashboard() {}


// A object is created for each type of sensor ande for security 
Security s;
Sensor sen;
Temperature temp;
Brightness brigh;
Humidity hum;
AirQuality airq;

DataBase* database;

// Heading
void Dashboard::cabecera() {
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

};


// Main menu wiht principal options
void Dashboard::set_dashboardEmployer() {
    while (true) {
        cabecera();
        cout << "\t\tOPCIONES DISPONIBLES\n\t\t-Sensores\t==> 1\n\t\t-Seguridad\t==> 2\n\t\t-Cerrar Sesión\t==> 3\n\t\t-Exit\t\t==> 0\n\t\t" << endl;

        cout << "----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "Seleccione una opcion escribiendo el número correspondiente.\n" << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
        switch (opcion) {
        case 0:
            goOut();
            break;
        case 1:
            goToSensors();
            break;
        case 2:
            goToSecurity();
            break;
        case 3:
            return;
        default:
                throw instructionException();
            }
        } catch (instructionException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }
    }
};

void Dashboard::set_dashboardAdmin() {
    
    while (true) {
        cabecera();
        cout << "\t\tOPCIONES DISPONIBLES\n\t\t-Sensores\t==> 1\n\t\t-Seguridad\t==> 2\n\t\t-Add Users\t==> 3\n\t\t-Erase Users\t==> 4\n\t\t-Cerrar Sesión\t==> 5\n\t\t-Exit\t\t==> 0\n\t\t" << endl;

        cout << "----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "Seleccione una opcion escribiendo el número correspondiente.\n" << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
        switch (opcion) {
        case 0:
            goOut();
            break;
        case 1:
            goToSensors();
            break;
        case 2:
            goToSecurity();
            break;
        case 3:
            addUserDashboard();
            break;
        case 4:
            eraseUserDashboard();
            break;
        case 5:
            return;
        default:
                throw instructionException();
            }
        } catch (instructionException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }
    }
};

// Submenu for the sensors
void Dashboard::goToSensors() {
    while (true) {
        // Heading and options
        cabecera();
        cout << "\t\tOPCIONES DISPONIBLES\n\t\t-Humidity\t==> 1 \n\t\t-Brightness\t==> 2 \n\t\t-Air Quality\t==> 3 \n\t\t-Temperature\t==> 4 \n\t\t-RBG cam\t==> 5 \n\t\t-Termal cam\t==> 6 \n\t\t-Exit\t\t==> 0" << endl;
        cout << "\n----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "Seleccione una opcion escribiendo el número correspondiente.\n" << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
            switch (opcion) {
            case 0:
            return;

            case 1:
                cabecera();
                hum.getData();
                break;

            case 2:
                cabecera();
                brigh.getData();
                break;

            case 3:
                cabecera();
                airq.getData();
                break;

            case 4:
                cabecera();
                temp.getData();
                break;
            
            case 5:
                cabecera();
                sen.getData(opcion);
                break;

            case 6:
                cabecera();
                sen.getData(opcion);
                break;
            default:
                throw instructionException();
            }
        } catch (instructionException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }
    }
};

// Submenu for the security
void Dashboard::goToSecurity() {
    while (true) {
        // Heading and options
        cabecera();
        cout << "\t\tOPCIONES DISPONIBLES\n\t\t-Puertas\t==> 1\n\t\t-Ventanas\t==> 2\n\t\t-Camaras\t==> 3\n\t\t-Alarma\t\t==> 4\n\t\t-Exit\t\t==> 0" << endl;
        cout << "\n----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "Seleccione una opcion escribiendo el número correspondiente.\n" << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
            switch (opcion) {
            case 0:
                return;
            case 1:
                cabecera();
                s.security("puertas");
                break;
            case 2:
                cabecera();
                s.security("ventanas");
                break;
            case 3:
                cabecera();
                s.security("camaras");
                break;
            case 4:
                cabecera();
                s.security("alarma");
                break;
            default:
                throw instructionException();
            }
        } catch (instructionException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }  
    }
};

// Message when the program is finished
void Dashboard::goOut() {
    system("clear");
    cout << "\x1b[41mSaliendo del sistema...\x1b[0m" << endl;
    database->writeUsers();
    exit(0);
}

void Dashboard::eraseUserDashboard() {
    while (true) {
        int opcion;
        cabecera();
        database->userList();
        cout << "\n----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\nIntroduzca el ID del usuario que desa borrar o introduzca 0 para volver" << endl;
        cout << database->actualID << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
            switch (opcion) {
            case 0:
                return;
            default:
                if (database->actualID == opcion) {
                    throw actualUserException();
                    break;
                } else {
                    database->eraseUser(opcion);
                }
            } 
        } catch  (actualUserException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }
    }
}

void Dashboard::addUserDashboard() {
    while (true) {
        cabecera();
        database->userList();
        cout << "\n----------------------------------------------------------------------------------------------------\n" << endl;
        cout << "Si desea añadir un usuario introduzca 1, para salir introduzca 0" << endl;
        cout << ">>> ";
        cin >> opcion;
        try {
            switch (opcion) 
            {
            case 1:
                cout << "Introduzca ID del nuevo usuario" << endl;
                cout << ">>> ";
                cin >> database->nuevoID;
                cout << database->nuevoID << endl;
                cout << "Introduzca NIF del nuevo usuario" << endl;
                cout << ">>> ";
                cin >> database->nuevoNIF;
                cout << database->nuevoNIF << endl;
                cout << "¿El usuario es adiministrador? (introduzaca 0 para NO, 1 para SI" << endl;
                cout << ">>> ";
                cin >> database->admin;
                database->addUser();
                break;
            case 0:
                return;
            default:
                throw instructionException();
            }
        } catch (instructionException &except) {
            cout << "Exception: " << except.what() << endl;
            system("sleep 2");
        }
        
    }
}

void Dashboard::dashboard(DataBase *base, bool isAdmin) {
    database = base;
    if (isAdmin) {
        set_dashboardAdmin();
    } else {
        set_dashboardEmployer();
    }
}

Dashboard* Dashboard::singleDashboard = nullptr;

Dashboard* Dashboard::getTheDashboard () {
    if (singleDashboard == nullptr)
        singleDashboard = new Dashboard ();
    else
        cout << "Error: trying to get another instance of a Ball singleton class!\n";

    return singleDashboard;
}