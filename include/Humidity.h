/**
 * @file Humidity.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Humidity sensor
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "Sensor.h"
using namespace std;

using namespace std;


class Humidity : Sensor{
    public:
    /**
     * @brief Construct a new Humidity object
     * 
     */
    Humidity();

    /**
     * @brief Get the Data object
     * 
     */
    void getData();
};

#endif