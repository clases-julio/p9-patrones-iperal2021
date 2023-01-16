/**
 * @file User.h
 * @author Iker Peral del Pino (i.peral.2021@alumnos.urjc.es)
 * @brief User object's file
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef USER_H
#define USER_H

class User {

    public:

    /**
     * @brief Construct a new User object
     * 
     * @param int the first is the ID
     * @param int the second is the NIF 
     * @param int the third is the role of the user
     */
    User(int = 0, int = 0, int = 0);
    
    bool operator== (const User &) const;

    void setNumRecord (int);

    int getNumRecord () const;

    /**
     * @brief Get the User ID
     * 
     * @return int 
     */
    int getUserID() const;

    /**
     * @brief Get the User NIF
     * 
     * @return int 
     */
    int getUserNIF() const;

    /**
     * @brief Get the User ADMIN
     * 
     * @return int 
     */
    int getUserADMIN() const;
    

    void setUserID (int);
   
    void setUserNIF (int);
   
    void setUserRole (int);

    /**
     * @brief overloading of the operator < to compare users
     * 
     * @return true 
     * @return false 
     */
    bool operator< (const User &) const;

    /**
     * @brief User atributes
     * 
     */
    protected:
    int ID ;
    int NIF;
    int ADMIN;
    int numRecord;
    
        
};
#endif