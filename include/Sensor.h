/**
 * @file Sensor.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief 
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Sensor {
    
    public:
    Sensor();
    
    /**
     * @brief Get the Data of the object
     * 
     */
    void getData(int);

    protected:
    /**
     * @brief Heading used in all the sensors
     * 
     */
    void cabeceraSensor();
    int back_1;

    /**
     * @brief Method that generate a random number 
     * which is used to show a value for each sensor
     * 
     * @return int 
     */
    int randomData();
    void goBackSensor();
};

#endif