/**
 * @file DataBase.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief DataBase implementation and validate users's methods.
 * @version 3.0
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <set>
#include "User.h"


class DataBase {
    
    public:
    /**
     * @brief Construct a new Data Base object
     * 
     */
    DataBase();


    /**
     * @brief list of the current usersd
     * 
     */
    void userList();

    /**
     * @brief Method to read the current users from the file users.dat
     * 
     */
    void readUsers();
    

    /**
     * @brief Methot used for write in the file users.dat the 
     * users at the end of the program
     * 
     */
    void writeUsers();

    /**
     * @brief Validates the users credentials that are stored in the database
     * 
     * @return true 
     * @return false 
     */
    bool validUser(int, int);

    /**
     * @brief bool to return the 
     * 
     */
    bool valided;

    /**
     * @brief method to erase users
     * 
     */
    void eraseUser(int);

    /**
     * @brief Method to add new users
     * 
     */
    void addUser();

    

    int nuevoID;
    int nuevoNIF;
    int admin;
    bool isAdmin;

    /**
     * @brief User that is used to login
     * 
     */
    int actualID;
    
    private:
    /**
     * @brief Users storage
     * 
     */
    std::set<User> vectorUser;
   
};
#endif