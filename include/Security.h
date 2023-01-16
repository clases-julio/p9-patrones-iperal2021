/**
 * @file Security.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Security methods
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SECURITY_H
#define SECURITY_H
#include <string>
#include <cstdlib>
using namespace std;

class Security {
    public:
    Security();
    string seguridad;

    /**
     * @brief Depend on the instruction, the security class
     * shows a different menu
     * @param string seguridad, depending on it's "value" the class shows a different menu
     */
    void security(string);

    private:
    void door();
    void window();
    void camera();
    void alarm();

    void open_close();

    /**
     * @brief Generate a random value and depend on it 
     * in some methods is used to generate a true or false value
     * 
     * @return int 
     */
    int generate_random();


    void goBackSecurity();
    
    string open;
    string alarma_status;
    
};
#endif