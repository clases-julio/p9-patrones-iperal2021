/**
 * @file Exceptions.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief Exception that may ocurr in the interface
 * @version 0.1
 * @date 2022-12-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>


/**
 * @brief If a string is introduced when an int is needed an exception will be thrown
 * 
 */
class stringException : public std::runtime_error {
    public:
    stringException()
    : std::runtime_error ("No se admiten letras o palabras, introduzca de nuevo") {}
};

/**
 * @brief If the ID or NIF are incorrect, the exception will be thrown
 * 
 */
class credentialException : public std::runtime_error {
    public:
    credentialException()
    : std::runtime_error ("El usuario y/o password son incorrectos") {}
};

/**
 * @brief If the instruction of the menu is wrong, the exception appears
 * 
 */
class instructionException : public std::runtime_error {
    public:
    instructionException()
    : std::runtime_error ("Instrucción incorrecta") {}
};

class actualUserException : public std::runtime_error {
    public:
    actualUserException()
    : std::runtime_error ("No puedes borrar el user usado actualmente") {}
};
#endif