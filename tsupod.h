/****************************************************
 * File Name: TsuPod.h
 * Author: Sarah Gibbons
 * Date: 4/22/15
 * Problem Number: 7
 * CS 2308 Spring 2015
 * Instructor: Priebe
 *
 * This is the Tsupod header file that contains the class
 * declaration, constant sizes, return error codes, and
 * functions
 *
 * *****************************************************/


#ifndef TSUPOD_H
#define TSUPOD_H
#include "Song.h"

//TsuPod class declaration
class TsuPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      int numSongs;
      int memSize;
    
      struct SongNode
      {
         Song s;
         SongNode *next; //to point to next node
      };
      
     SongNode *head;  //the head pointer
      
    
   
   public:
      TsuPod();
      TsuPod(int size);
      
      int addSong(Song const &s);
      int removeSong(Song const &s);
      int sortSongList();
    
      void shuffle();
      void showSongList();
      int getRemainingMemory();
      void getTotalMemory(int);
      int clearSongList();
   
    ~TsuPod(); //destructor

   
 
};



#endif
