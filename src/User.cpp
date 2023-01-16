/* ---------------------------
File: User.cpp
Author: Iker Peral del Pino
Date: 22/11/2022
Goal: Class to create user objects
---------------------------- */

#include <iostream>
#include "User.h"
using namespace std;


// User atributes
int ID;
int NIF;
int ADMIN;

User::User(int id, int nif, int admin) { // Constructor
    setUserID (id);
    setUserNIF (nif);
    setUserRole (admin);
}  


// As their name indicates, each method give the data which is asked for
int User::getUserADMIN() const {
    return ADMIN;
}

int User::getUserID() const {
    return ID;
}

int User::getUserNIF() const {
    return NIF;
}

void User::setUserRole (int myRole) {
  ADMIN = myRole;
}

void User::setUserNIF (int myNif) {
  ID = myNif;
}

void User::setUserID (int myId) {
  NIF = myId;
}

// Method to compare users
bool User::operator< (const User &user) const {
    return ID < user.ID; 
}

bool User::operator== (const User &user) const {
    if (ID == user.ID && NIF == user.NIF) {
        return true;
    } 
    return false;
}

int User::getNumRecord() const {
        return numRecord;
}

void User::setNumRecord (int record) {
        numRecord = record;
}