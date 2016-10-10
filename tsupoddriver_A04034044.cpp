/****************************************************
 * File Name: TsuPod_Driver.cpp
 * Author: Sarah Gibbons
 * Date: 4/22/15
 * Problem Number:
 * CS 2308 Spring 2015
 * Instructor: Priebe
 *
 * This is the Tsupod driver file that is intended to test
 * the functionality of the tsupod program
 ********************************************************/
#include <cstdlib>
#include <iostream>
#include<string>
#include "song.h"
#include "tsupod.h"


using namespace std;

int main()
{
    TsuPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
    
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
    
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    return 0;
    
    }
