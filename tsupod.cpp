/****************************************************
 * File Name: TsuPod.cpp
 *
 * Author: Sarah Gibbons
 * Date: 4/22/15
 * Problem Number: 7
 * CS 2308 Spring 2015
 * Instructor: Priebe
 *
 * This contains the constructors for the TsuPod class
 * and function definitions
 *
 ******************************************************/
#include"tsupod.h"
#include"song.h"

#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

TsuPod::TsuPod() //constructor
{
    head=NULL;
    memSize = MAX_MEMORY;
    numSongs=0;
}

TsuPod::TsuPod(int n)
{
    n=numSongs;
    
}
//function to show song list
void TsuPod::showSongList()
{
    SongNode * target = head;
    
    cout << fixed << setw(22) << "Artist" << setw(22) << "Title" << setw(22)
    << "Size" << endl;
    if (!target)
        cout << "No songs found.";
    while (target!=NULL)
    {
        cout << setw(22) << target->s.getArtist()
        << setw(22) << target->s.getTitle()
        << setw(20) << target->s.getSize() << "MB" << endl;
        target = target->next;
    }
    cout << endl;
}


//function to get remaining memory
int TsuPod::getRemainingMemory()
{
    return memSize;
    
}

//function to add Song to TsuPod
int TsuPod::addSong(Song const &s)
{
    //check to see if enough memory
    if(getRemainingMemory()>=s.getSize())
    {
        //create new node
        SongNode *temp = new SongNode;
        temp->s= s;
        temp->next = NULL;
        
        if(!head) //checking position
        {
            head = temp;
            getTotalMemory(-(temp->s.getSize()));
            numSongs++;
            
            return 0;
            
        }
        else
        {
            SongNode * target = head;       //insert new node at end of list
            while(target->next)
            {
                target= target->next;
                target->next = temp;
                getTotalMemory(-(temp->s.getSize()));
                numSongs++;
            }
            
                while (target != NULL)    //find last node at end of list
                {
                    temp = target;
                    target = target->next;      //finding end
                    //delete temp;
                    //target->next = temp;
                    
                    getTotalMemory(-(temp->s.getSize()));
                    numSongs++;
                }
    
                return 0;
        }
    }
    
    return NO_MEMORY;
}
//function to remove Song to TsuPod
int TsuPod::removeSong(Song const &s)
{
    
    SongNode * previous = head;
    SongNode * current = head->next;
    
    if (head->s == s)
    {
        getTotalMemory((head->s.getSize()));
        numSongs--;
        head = head->next;
        delete previous;
        return 0;
    }
    else
        while (current)
        {
            if (current->s == s)
            {
                getTotalMemory(current->s.getSize());
                numSongs--;
                
                previous->next = current->next;
                delete current;
                return 0;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    return -1;
}


void TsuPod::getTotalMemory(int mb)
{
   memSize +=mb;
}


//shuffleSong: function shuffles songs from list
void TsuPod::shuffle()
{
    unsigned int currentTime =  (unsigned)time(0);
    
    srand(currentTime);
    
    int index1 = (rand()% numSongs);
    int index2 = (rand()% numSongs );
    
    SongNode *p1 = head;
    for (int i = 0; i < index1; i++)
    {
        p1 = p1 -> next;
    }
    
    SongNode *p2 = head;
    for (int i = 0; i < index2; i++)
    {
        p2 = p2 -> next;
    }
    
    Song temp = p1 -> s;
    p1 -> s = p2 -> s;
    p2 -> s = temp;
}

//function using selection sort to sort the songs in order
int TsuPod::sortSongList()
{
    
    for(SongNode *p1 = head; p1 != NULL; p1 = p1 -> next)
    {
        SongNode *small = p1;
            
        for(SongNode *p2 = p1 -> next; p2 != NULL; p2 =  p2 -> next)
        {
            if(small->s > p2->s)
                small = p2;
        }
            
            if(p1 != small)
            {
                Song temp = small -> s;
                small -> s = p1 -> s;
                p1 -> s = temp;
            }
    }
       return 0;
}

//function that clears song list and sets list head to null
int TsuPod::clearSongList()
{
    if (!head)
        return -1;
    
    SongNode * nodeptr = head;
    SongNode * nextNode;
    
    while (nodeptr)
    {
        nextNode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextNode;
    }
    
    memSize = MAX_MEMORY;
    numSongs= 0;
    head = NULL;
    
    return 0;
}


TsuPod::~TsuPod()   //destructor
{
    SongNode *p = head;
    
    while(p!=NULL)
    {
      head = head->next;
      delete p;
      p= head;
    }
    
}

    
