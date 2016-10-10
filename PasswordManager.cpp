
/********************************************
 * PasswordManager.cpp
 *
 * Sarah Gibbons
 * October 21, 2015
 * CS2308-00X - Project #4
 * The passwordManager has two private classes
 * and five bulic classes that test the behavior
 * of the class. 
 *
 ********************************************/

#include "PasswordManager.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstring>
#include<fstream>

using namespace std;

const int VALIDATION_ERROR = 0;
const int VALIDATION_SUCCESS = 1;

// ==========================================================================
// Private function: encrypt(string nString)
// This function takes a string password and returns the encrypted form 
// returns encrypted string
// ==========================================================================
string PasswordManager::encrypt(string nString) const {
    const int KEY =26;  
   
    int strLen = (nString.length()); //grab str length
   
    string encryptedStr(nString); 

    for(int i = 0; i < nString.length(); i++) {
        encryptedStr[i] = nString[i] ^ KEY; 
    }
    //store all encrypted chars in a new string to return
    //do not change the argument passed in and do not modify
    //class member variable 
    return encryptedStr; 
    
}
// ==========================================================================
// Private function: validatePassword();
// This function takes a canidate password and returns true if it is at least
// 8 characters long, contains at least one uppercase letter, one lowercase
// letter, one digit and one symbol character. Otherwise is returns false.
// ==========================================================================
bool PasswordManager::validatePassword (string str) const {
    
    bool upper = false;
    bool lower = false;
    bool is_digit = false;
    bool is_punct = false;
    
    int strlength = (str.length());
    
    if (strlength >= 8)
        return VALIDATION_SUCCESS;
    else
        return VALIDATION_ERROR;
       
    for(int count = 0; count < strlength; count++) {
        
        if (isupper(str[count])){
            upper = true;
            
        }
        if (islower(str[count])){
            lower = true;
            
        }
        
        if (isdigit(str[count])) {
            is_digit = true;
            
        }
        
        if(ispunct(str[count])) {
            is_punct= true;
        }
        
    }
    if(upper == true && lower == true && is_digit == true && is_punct == true) {
        return VALIDATION_SUCCESS;
    }
    else
        return VALIDATION_ERROR;
}
// ==========================================================================
// Public function: getEncryptedPassword();
// returns encryptedPassword
// returns encryptedPassword;
// ==========================================================================
string PasswordManager::getEncryptedPassword () const {
   
    return encryptedPassword;  
}

// ==========================================================================
// Public function: setNewPassword
// This mutator function takes a proposed password and if it meets the 
// criteria in validatePassword then it encrypts it and stores it in the
// member variable and returns true 
// returns meetsCritera;
// ==========================================================================
bool PasswordManager::setNewPassword(string propPassword) {
   
    if (validatePassword(propPassword)==true) {
        string password = encrypt(propPassword); //call encrypt
        encryptedPassword = password; //stores in member variable
        return VALIDATION_SUCCESS;
    }
    else
    return VALIDATION_ERROR;
}

// ==========================================================================
// Public function: checkPassword(string enpass) const
// This function takes a string text password and returns true if it matches
// the encrypted string stored in the member variable else returns false
// ==========================================================================
bool PasswordManager::checkPassword (string enpass) const {
    string checkEncryptedpassword = getEncryptedPassword(); 

    if (checkEncryptedpassword == encrypt(enpass)) 
        return VALIDATION_SUCCESS;
    else
        return VALIDATION_ERROR;
}
// ==========================================================================
// Public function: storeEncryptedPassword (string outputfile) const
// This function takes an output filename, opens the file, writes to the file
// and closes the file. Returns true on success, false otherwise
// ==========================================================================
bool PasswordManager::storeEncryptedPassword(string outputfile) const {
    ofstream fout;
    string password = encryptedPassword;
    fout.open(outputfile.data()); 
       
        if(!fout.eof()) {
            fout << password << endl; 
        }
    fout.close(); 
    return VALIDATION_SUCCESS;
}
// ==========================================================================
// Public function: loadEncryptedPassword(string inputfile) const
// This mutator function takes an input filename, reads from the file and 
// stores the contents into the member variable
// returns true on success, false otherwise
// ==========================================================================
bool PasswordManager::loadEncryptedPassword(const char * inputfile) const {
    ifstream fin;
    fin.open(inputfile); 
    string password; 
    bool verified; 
    verified = validatePassword(password); 
    if(!fin){
        cout << "Error opening input file.\n";
        return false;
    }
    
    while(!fin.eof()) {
       fin >> password; 
    }
    if(verified){
      encryptedPassword == encrypt (password); 
      return verified;
     fin.close();  
    } 
    else
        return VALIDATION_ERROR;
}


