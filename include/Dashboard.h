/**
 * @file Dashboard.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief main menu
 * @version 3
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <string>
#include <iostream>
#include "DataBase.h"
using namespace std;

class Dashboard {
    public:
    Dashboard();

    /**
     * @brief Principal header with the name of the business
     * 
     */
    void cabecera();

    /**
     * @brief Set the menu for the employers
     * 
     */
    void set_dashboardEmployer();

    /**
     * @brief Set the menu for the Admins
     * 
     */
    void set_dashboardAdmin();

    void dashboard(DataBase*, bool);

    static Dashboard* getTheDashboard();
    Dashboard (Dashboard&otherDashboard) = delete; // singletons should not be cloneable
    void operator= (const Dashboard&) = delete; // singletons should not be assignable

    private:

    /**
     * @brief Menu with options for the security 
     * 
     */
    void goToSecurity();

    /**
     * @brief menu that shows the different sensors. 
     * For each instruction a sensor is shown
     * 
     */
    void goToSensors();

    /**
     * @brief  Function to exit the program when the option is selected.
     * 
     */
    void goOut();
    void goBack();

    /**
     * @brief Method that allow the admin to erase the users
     * 
     */
    void eraseUserDashboard();

    /**
     * @brief Function that allows the admin to add new users
     * 
     */
    void addUserDashboard();
    int opcion;
    int pantalla;
    DataBase* database;
    
    static Dashboard* singleDashboard;
};
#endif