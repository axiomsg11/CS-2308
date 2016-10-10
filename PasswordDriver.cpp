/********************************************
 * PasswordDriver.cpp
 *
 * Sarah Gibbons
 * October 21, 2015
 * CS2308-00X - Project #4
 *
 * The main function tests the functionality 
 * of the public functions in PasswordManager
 * class. 
 ********************************************/
#include<iostream>
#include "PasswordManager.h"

using namespace std;

// ==========================================================================
// Function main(): makes function calls to the PasswordManager member 
// functions to test them. It prints the expected output and the actual 
// returns 0
// ==========================================================================
int main()
{  
    int x = 26; //used to unencrypted getEncryptedPassword 
    string test0 = "H3ll0W";
    string test1 = "H3ll0W@rld!";
    string pass1_ENC = ""; 
    string pass_UNENC = ""; 
    PasswordManager p;
  
    cout << "Test case #1: setNewPassword(), password denied (not at least 8 characters)" << endl; 
    cout << "Test data:" <<test0 << endl; 
    bool result0 = p.setNewPassword(test0); 
    cout << "Expected: 0" << endl; 
    cout << "Actual : " << result0 <<endl; 
    cout << endl; 

    cout << "Test case #2: setNewPassword(), password accepted" << endl;
    cout << "Test data: " << test1 << endl;
    bool result = p.setNewPassword(test1);
    cout << "Expected: 1" << endl;
    cout << "Actual  : " << result << endl;
    cout << endl; 

    cout << "Test case #3: getEncryptedPassword(), initialized data (and also tests ecryption)" << endl;
    string actual = p.getEncryptedPassword();
    cout << "Expected: " <<"R)vv*MZhv~;"<< endl;   
    cout << "Actual  : " << actual << endl;
    cout << endl; 

    cout << "Test case #4: getEncryptedPassword(), unencrypts by xor twice" << endl; 
    cout << "Expected:" << "H3ll0 W@rld" <<endl;
   
    for(int temp = 0; temp < test1.length(); temp++) {
        pass_UNENC += actual[temp] ^x; }
    cout << "Actual:" << pass_UNENC << endl; 
    cout << endl; 

    cout << "Test case #5: checkPassword(), (does not match password)" << endl; 
    bool result1 = p.checkPassword(pass1_ENC); 
    cout << "Expected: 0" << endl;
    cout << "Actual:" << result1 << endl; 
    cout << endl; 

    cout << "Test case #6: checkPassword(), (matches the password)" << endl; 
    bool result2 = p.checkPassword(test1); 
    cout << " Expected: 1" << endl; 
    cout << " Actual:" << result2 << endl; 
    cout << endl; 

    cout << "Test case #7: storeEncryptedPassword, successfully opens file and writes to it " << endl; 
    bool testFile = p.storeEncryptedPassword("outputfile.data"); 
    cout << "Expected: 1" << endl; 
    cout << "Actual:" << testFile << endl;     
    cout << endl; 

    cout << " Test case #8: loadEncryptedPassword, inputfile data is not valid" << endl; 
    bool testInfile = p.loadEncryptedPassword("inputfile.data"); 
    cout << "Expected: 0" << endl;
    cout << "Actual: " << testInfile << endl;   
    return 0; 
}

