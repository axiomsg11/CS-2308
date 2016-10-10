/****************************************************
 File Name: Song.h
 Author: Sarah Gibbons
 Date: 04/22/15
 Problem Number:7
 CS 2308 Spring 2015
 Instructor: Priebe
 
 This is the Song.h file. It contains the class Song
 and functions used in the tsuPod files
 *****************************************************/
#ifndef SONG_H
#define SONG_H

#include<iostream>
#include<string>

using namespace std;

class Song
{
private:
    string title,
    artist;
    int size;
    
public:
    //accessors
    string getArtist() const;
    string getTitle()const;
    int getSize()const;
    
    //Mutators
    void setSongTitle(string);
    void setSongArtist(string);
    void setSongSize(int);
    
    Song(); //constructor
    Song(string title, string artist, int size); //constructor
    
    //Operator Overload
    bool operator<(const Song &rhs);
    bool operator>(const Song &rhs);
    bool operator==(const Song &rhs);
    
};



#endif
