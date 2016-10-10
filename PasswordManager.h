/******************************************
 * PasswordManager.h
 * 
 * Sarah Gibbons
 * October 21, 2015
 * CS2308-00X – Project #4
 * This PasswordManager class has a single 
 * private member variable that stores the 
 * encrypted password and two private functions
 * and five public functions that can be 
 * accessed from outside the class and test
 * the functionality of the class.
 * ******************************************/
#ifndef passwordmanager_h
#define passwordmanager_h

#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std; 

class PasswordManager {
private:
    string encryptedPassword; //single member variable that stores encrypted password not accessible from outside class
	//two internal member functions
    string encrypt(string) const;
    bool validatePassword (string ) const;
	
public:
   // string getEncryptedPassword () const;
    bool setNewPassword(string);
    string getEncryptedPassword () const; 
    bool checkPassword (string) const;
    bool storeEncryptedPassword(string) const;
    bool loadEncryptedPassword (const char *) const;
    
    
    
    
};



#endif
