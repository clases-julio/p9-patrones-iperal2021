/**
 * @file Employer.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Object employer
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "User.h"
using namespace std;


class Employer : User{
    public:
    Employer();
    int ADMIN = 0;
};
#endif