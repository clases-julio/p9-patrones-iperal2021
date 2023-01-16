/**
 * @file AirQuality.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Air Quality sensor
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef AIRQUALITY_H
#define AIRQUALITY_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "Sensor.h"
using namespace std;

class AirQuality : Sensor{
    public:
    AirQuality();
    void getData();
};

#endif