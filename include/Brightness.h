/**
 * @file Brightness.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Luminosity sensor
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "Sensor.h"
using namespace std;


class Brightness : Sensor{
    public:
    Brightness();
    void getData();
};

#endif