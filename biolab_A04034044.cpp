
/****************************************************
File Name: biodataHelp_A04034044.cpp

Author: Sarah Gibbons
Date: 01/27/15
Problem Number: 1
CS 2308 Spring 2015
Instructor: Priebe

Brief description of the contents and purpose

*****************************************************/
#include <iostream>
#include<fstream>
#include <string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include <stdlib.h>
using namespace std;
string getYear(string date);
string getMonth(string date);
string getDay(string date);
string getHour(string date);
string getMin(string date);

float convertstof(string Ftemp);
float getCelsius(string Ctemp);


int main()
{
    ifstream fin;
    fin.open("biodata.txt");
    ofstream fout;
    fout.open("results.txt");

    if(fin.fail())
    cout<<"file didnt open correctly"<<endl;

string numData;
fin>>numData;
string date;
string temp;
float total = 0;
int counter = 0;

    while (fin>>date>>temp)
    {
        string year=getYear(date);
        string month = getMonth(date);
        string day = getDay(date);
        string hour = getHour(date);
        string minute = getMin(date);
        float temp1 = convertstof(temp);

        fout<<setprecision(4)<<temp1<<" C --";
        fout<<"recorded on "<<year<<"/"<<month<<"/"<<day<<"  - "<<hour<<":"<<minute<<endl;

        total += temp1;
        counter++;
    }

        fout<<"Average Temp -- "<<setprecision(4) <<total/counter;

        fin.close();
        fout.close();
        return 0;
    }


string getYear(string date)
{
    string year = date.substr(0,4);
    return year;
}
string getMonth(string date)
{
    string month = date.substr(4,2);
    return month;
}
string getDay(string date)
{
    string day = date.substr(6,2);
    return day;
}
string getHour(string date)
{
   string hour = date.substr(8,2);
   return hour;
}
string getMin(string date)
{
    string minute = date.substr(9,2);
    return minute;
}

float convertstof(string Ftemp)
{
     float temp;
     setprecision(2);
     string scale = Ftemp.substr(0,1);
     string temperature = Ftemp.substr(1);
     string ch = "F";

     temp = atof(temperature.c_str());

    if(scale == ch)
    {
        temp = (temp -32) * 5.0/9.0;
    }
    return temp;
}


