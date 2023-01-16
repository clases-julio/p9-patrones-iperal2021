/**
 * @file Temperature.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Temperature sensor
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "Sensor.h"
using namespace std;


class Temperature : Sensor{
    public:
    /**
     * @brief Construct a new Temperature object
     * 
     */
    Temperature();

    /**
     * @brief Get the object data
     * 
     */
    void getData();
};

#endif