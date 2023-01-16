/* ---------------------------
File: main.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: this program starts the main program
---------------------------- */


// all the libraries needed
#include <iostream>
#include <string>
#include <cstdlib> // for random number generator
#include <set>
#include "DataBase.h"
#include "Login.h"
#include "Dashboard.h"
using namespace std;

int main() {
    DataBase* ptrbase;
    try {
        ptrbase = new DataBase();
    } catch (bad_alloc &except) {
    cerr << "Exception!: " << except.what() << endl;
    }

    ptrbase->readUsers();
    // a login and a dashboard objects are created
    Login* login = Login::getTheLogin ();
    Dashboard* dashboard = Dashboard::getTheDashboard ();
    while (true) {
       
        system("clear"); // used in lots of functions to clear the screen
        login->login(ptrbase); // initialize the login screen
        dashboard->dashboard(ptrbase, login->go_to_dashboard());
    }
    return 0;
}
