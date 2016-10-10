/****************************************************
 * File Name: Song.cpp
 * Author: Sarah Gibbons
 * Date: 4/22/15
 * Problem Number: 7
 * CS 2308 Spring 2015
 * Instructor: Priebe
 *
 * This is the Song.cpp file. It contains instance variables
 * and overload operater functions used in sorting
 *********************************************************/


#include"song.h"
#include"tsupod.h"
#include<string>
#include<cstring>

string Song::getArtist() const
{
    return artist;
}

string Song::getTitle()const
{
    return title;
    
}
int Song::getSize() const
{
    return size;
}
void Song::setSongTitle(string t)
{
    title = t;
}

void Song::setSongArtist(string a)
{
    artist = a;
}

void Song::setSongSize(int s)
{
    size = s;
}

Song::Song()
{
    title= " ";
    artist = " ";
    size =0;
}
Song::Song(string _artist, string _title, int _size)
{
    artist=_artist;
    title=_title;
    size = _size;
}
bool Song::operator < (const Song &rhs)
{
    if(getArtist()!=rhs.getArtist())
    {
        return getArtist() <rhs.getArtist();
    }
    if(getTitle() != rhs.getTitle())
    {
        return getTitle() <rhs.getTitle();
    }
    
    return getSize() < rhs.getSize();
    
}


bool Song::operator> (const Song &rhs)
{
    if(getArtist()!=rhs.getArtist())
    {
        return getArtist() > rhs.getArtist();
    }
    
    if(getTitle() != rhs.getTitle())
    {
        return getTitle() >rhs.getTitle();
    }
    
    return getSize()> rhs.getSize();
    
}

bool Song::operator==(const Song &rhs)
{
    if(getTitle() != rhs.getTitle())
        return false;
    if (getArtist() != rhs.getArtist())
        return false;
    if (getSize() != rhs.getSize())
        return false;
    else
        return true;
    
    
}
