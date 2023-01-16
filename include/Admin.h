/**
 * @file Admin.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "User.h"
using namespace std;


class Admin : User{
    public:
    Admin();
    int ADMIN = 1;
};
#endif