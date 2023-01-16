/**
 * @file Login.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Login interface
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <set>


class Login {
    public:
    Login();
    void go_back();
    bool go_to_dashboard();
    void set_login();
    void login(DataBase*);

    static Login* getTheLogin();
    Login (Login &otherLogin) = delete; // singletons should not be cloneable
    void operator= (const Login&) = delete; // singletons should not be assignable

    private:
    /**
     * @brief method that calls a database function which verify the credentials
     * If the function return a false, a mesage is printed to show the user that is wrong
     * At the third wrong try the program finishes with a 'access denied' error
     */
    void comprobar_user_data();   

    /**
     * @brief Method to get the ID
     * 
     */
    void get_NIF();

    /**
     * @brief Method to get the NIF
     * 
     */
    void get_ID();

    /**
     * @brief Variable of the data base type wich save a pointer
     * 
     */
    DataBase* database;

    bool data_valid;
    int intentos;
    int contador;
    int temp_ID;
    int temp_NIF;
    static Login* singleLogin;
};
#endif