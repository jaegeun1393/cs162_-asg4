/*********************************************************************
** Program Filename: room.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: room implment
** Input: user inputs
** Output: room information
*********************************************************************/
#ifndef _ROOM
#define _ROOM
#include<iostream>
#include<cstdlib>
#include<time.h>

#include "bats.hpp"
#include "pit.hpp"
#include "gold.hpp"
#include "wumpus.hpp"

using namespace std;

class Room {
    protected:
    Event *location;
    char event, player;
    public:
        Room();
       char get_event();
       string get_message();
       void set_event(char event);
       void set_Wumpus();

        ~Room();

};

#endif