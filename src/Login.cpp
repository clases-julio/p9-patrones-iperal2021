/* ---------------------------
File: Login.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: this program requests for authentication
---------------------------- */


// Needed libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>
#include "Dashboard.h"
#include "DataBase.h"
#include "Login.h" 
#include "Exceptions.h"

using namespace std;



Login::Login() {} // Login constructor

// These variables are used to create temporal ID and NIF
int temp_ID;
int temp_NIF;

bool data_valid = false; 

// these variables are used to have a counter of the times the user is trying to login
int contador = 0;
int intentos = 3;


// --------------------------------
// Methods to save the credentials introduced by the user
void Login::get_ID() {
    string id;
    cout << "\n\tID: ";
    cin >> id;
    try {
        temp_ID = stoi(id);
    }
    catch (std::invalid_argument) {
        cout << "Exception: chars and string are invalid" << endl;
    }
    catch (std::out_of_range) {
        cout << "Exception: ID lenght out of range" << endl;
        system("sleep 1");
    };
};

void Login::get_NIF() {
    string nif;
    cout << "\n\tNIF: ";
    cin >> nif;
    try {
        temp_NIF = stoi(nif);
    }
    catch (std::invalid_argument) {
        cout << "Exception: chars and string are invalid" << endl;
        system("sleep 1");
    }
    catch (std::out_of_range) {
        cout << "Exception: NIF lenght out of range" << endl;
        system("sleep 1");
        
    }
};

// ---------------------------------

/*  Method to call the database and validate the credentials
    if them are false the login restart and indicates the user
    that credentials are wrong*/
void Login::comprobar_user_data() {
    
    try {
    data_valid = database->validUser(temp_ID, temp_NIF);
        if (!data_valid) {
            throw credentialException();
        }
    }
    catch (credentialException &except) {
        cout << "\n\n\tException: "<< except.what() << endl;
        contador++;
        system("sleep 1.5");
        if (contador != 3) {
            system("clear");
        } else {
            // at the third try the program finish and denied the access
            cout << "\u001b[31m\n\t\t\tAccess denied.\u001b[0m\n" << endl;
            go_back();
        }
    }
};

bool Login::go_to_dashboard() {
    
    system("sleep 1");
    if (database->isAdmin) {
        return true;
    }
    return false;
};

void Login::go_back() {
    exit(0);
};

// -------------------------------
//          Main Login
void Login::set_login() {
    while (true) {
        // Title
        cout << "\t\t\t----------------" << endl;
        cout << "\t\t\t\x1b[47m\x1b[30mLOGIN DE USUARIO\x1b[0m" << endl;
        cout << "\t\t\t----------------" << endl;

        // The credentials are asked and are validated
        get_ID();
        get_NIF();

        comprobar_user_data();
        

        // If the credentials are correct the user goes to the dashboard
        if (data_valid == true) {
            database->actualID = temp_ID;
            cout << database->actualID << endl;
            cout << "\u001b[32m\n\n\t\t\tBienvenido al sistema\u001b[0m" << endl;
            contador = 0;
            return;
        } 
    }   
};

// Method used to call the main login 
void Login::login(DataBase* data) {
    database = data;
    system("clear");
    set_login();
    go_to_dashboard();
    
};

Login* Login::singleLogin = nullptr;

Login* Login::getTheLogin () {
  if (singleLogin == nullptr)
    singleLogin = new Login ();
  else
    cout << "Error: trying to get another instance of a Ball singleton class!\n";

  return singleLogin;
}