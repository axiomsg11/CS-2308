/****************************************************
 * File Name: Converter_A04034044.cpp
 *
 * Author: Sarah Gibbons
 * Date:4 /30/15
 * Problem Number:
 * CS 2308 Spring 2015
 * Instructor: Priebe
 *
 * Given an integer base 10 this program converts another
 * base using stack provided the STL
 *
 * *****************************************************/

#include<iostream>
#include<stack>
#include<cstdlib>
#include<stdlib.h>

using namespace std; 

int main(int argc, char *argv[]){

   stack <char> char_stack; 

   //count the number of elements is correct
   if(argc!=3){

    cout<<"Incorrect usage:correct usage is:converter_A04034044.cpp numberToConvert newBase"<<endl; 

    return 0; 
   }
//function atoi(char*) will convert c string to int
 int numberToConvert = atoi(argv[1]); //assign numberToConvert to file name (?)
 
 int newBase = atoi(argv[2]); 
 int copy = numberToConvert; 

 while(copy) {
    char_stack.push("0123456789ABCDEF"[copy%newBase]);
    copy= copy/newBase; 
 }  

 cout<<numberToConvert<<"-base 10"<<endl;

//check stacks not empty
 while(!char_stack.empty()) {
 cout<<char_stack.top(); 
 char_stack.pop(); 
 
}
 cout<<"- base"<<newBase<<endl; 
return 0; 
}
