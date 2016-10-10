 /****************************************************
 *  matchBrackets_A04034044.cpp
 *
 * Author: Sarah Gibbons
 * Date: 11/20/15
 * CS 2308 - Project #7
 *
 * This problem uses a stack to keep track of brackets
 * and checks for missing parenthesis, curly braces and
 * missing brackets. 
 ******************************************************/


#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{  
   //take single command line argument and name of file to parse 
    if (argc != 2) {
        cout << "Incorrect usage:correct usage is: ./match matchBrackets_A04034044.cpp mat" << endl;
        return 0;
    }
     
    ifstream fin; 
    fin.open(argv[1]);
    stack <char> charStack;
    string strline; 
    int lineNumber = 0; 
    while (fin >> noskipws >> strline) {
        lineNumber++;  
        getline(fin, strline);
      //store expecting closing brackets on stack when encounter opening bracket  
        for (int i = 0; i <= strline.length(); i++) { 
           if(strline[i] =='(')
               charStack.push(')'); 
           if(strline[i] == '[')
               charStack.push(']'); 
           if(strline[i] =='{')
               charStack.push('}');  
           if(strline[i] == ')' || strline[i] == ']' || strline[i] == '}') 
              if(charStack.empty())
                 break;  
           else if (!charStack.empty() && strline[i] == ')' || strline[i] == ']'|| strline[i] == '}')// push closers onto stack then pop them?   
               if((charStack.top() == strline[i]))
                 charStack.pop();
        } 
        if(charStack.empty()) 
            cout << strline << " contains an extra or unmatched bracket " << endl;
         else {
         cout << strline << " === missing " << charStack.top() << " On line # : " << lineNumber<< endl;
         charStack.pop();
         } 
         while (!charStack.empty())charStack.pop();
    }
    return 0;
}
