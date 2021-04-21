/*********************************************************************
** Program Filename: room.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: Set up the room and make a space to place logo
** Input: user inputs
** Output: Set up the map
*********************************************************************/

#include "room.hpp"

using namespace std;

/*********************************************************************
** Function: Room
** Description:  Set up the map of the game (basic)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Room::Room() {
    event = ' ';
    location = NULL;
    player = 'x';
    srand(time(NULL));
}

/*********************************************************************
** Function: get_event
** Description:  return the event of the room 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
char Room::get_event() {
    return event;
}

/*********************************************************************
** Function: set_event
** Description:  set the event on the every room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Room::set_event(char event) {
    this->event = event;

    if (event == 'w') {
        location = new Wumpus;
    }
    else if(event == 'b') {
        location = new Bats;
    }
    else if(event == 'g') {
        location = new Gold;
    }
    else if(event == 'p') {
        location = new Pit;
    }
    else if(event == ' ') {
        location = NULL;
    }
}

/*********************************************************************
** Function: get_message
** Description:  bring the message from the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
string Room::get_message() {
    return location->get_message();
}

/*********************************************************************
** Function: ~ROOM
** Description: prevent memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Room::~Room() {
        delete location;
}
