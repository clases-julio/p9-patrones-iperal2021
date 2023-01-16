/* ---------------------------
File: DataBase.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: DataBase with the user information
---------------------------- */
#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <iomanip>
#include "DataBase.h"
#include "User.h"
#include "Exceptions.h"

using namespace std;


bool valided;
int nuevoID;
int nuevoNIF;
int admin;

// Constructor with the default users
DataBase::DataBase() { 
    /*User* user1 = new User(1111, 12345678, 0);
    User* user2 = new User(2222, 23456789, 0);
    User* user3 = new User(3333, 34567890, 0);
    User* user4 = new User(1212, 12121212, 1);
    vectorUser.insert(*user1);
    vectorUser.insert(*user2);
    vectorUser.insert(*user3);
    vectorUser.insert(*user4);*/

}

// Main method
// Used to validate the credentials of the user 
bool DataBase::validUser(int id, int nif) {

    /*  For each user in the list the atributes ID and NIF are compared whit 
        the ones introducted by the user from the login*/
    for (User u : vectorUser) {

        if (u.getUserID() == id && u.getUserNIF() == nif) {
            // when the correct user is found the loop is over
            valided = true;
            if (u.getUserADMIN() == 1) {
                isAdmin = true;
            } else {
                isAdmin = false;
            }
            
            
            break;
        } else {
            valided = false;
        }
    }
    return valided;
}

void DataBase::eraseUser(int posicion) {

    for (User u : vectorUser) {
        if (posicion == u.getUserID() ) {
            vectorUser.erase(u);
            break;
        } 
    }  
}

void DataBase::addUser() {

    for (User u : vectorUser) {

        if (u.getUserID() == nuevoID || u.getUserNIF() == nuevoNIF) {
            
            cout << "ID o NIF ya existentes" << endl;
            break;
        } else {
            vectorUser.insert(User(nuevoNIF, nuevoID, admin));
        }
    }
}


void DataBase::readUsers() {
    ifstream inUsersFile ("./resources/users.dat", ios::in | ios::binary);
    
    
    if (!inUsersFile) { // file couldn't be opened
        cerr << "File could not be opened" << endl;
        exit (1);
    }

    User user;
    
    inUsersFile.read (reinterpret_cast <char *>(&user), sizeof (User));
    
    while (inUsersFile && !inUsersFile.eof()) {
        if (user.getNumRecord() != 0) {
            vectorUser.insert (user);
        }
        inUsersFile.read (reinterpret_cast <char *>(&user), sizeof (User));
    }
    
}


void DataBase::writeUsers() {
    int numRecord = 1;

    fstream outUsersFile ("./resources/users.dat", ios::out | ios::binary | ios::trunc);

    
    if (!outUsersFile) { // file couldn't be opened
        cerr << "File could not be opened" << endl;
        exit (1);
    }

    for (User u : vectorUser) {
       
        User user(u.getUserNIF(), u.getUserID(), u.getUserADMIN());
        user.setNumRecord (numRecord);

        outUsersFile.seekp ((user.getNumRecord() - 1 ) * 
        sizeof (User));

        outUsersFile.write (reinterpret_cast <const char *> (&user),
        sizeof (User));
        numRecord++;
    }  
}

void DataBase::userList() {
    int posicion = 1;
    for (User u : vectorUser) {
        cout << "\t" << posicion << " -\t" << u.getUserID() << "\t" << u.getUserNIF() << endl;
        posicion += 1;
    }
}