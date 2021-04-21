/*********************************************************************
** Program Filename: wumpus.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: wumpus implment
** Input: user inputs
** Output: set up the wumpus
*********************************************************************/
#include "wumpus.hpp"
using namespace std;

/*********************************************************************
** Function: Wumpus
** Description: Set up the Wumpus message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Wumpus::Wumpus() {
    message = "You smell a aterrible stench.";
    alive = true;
    eventletter = 'w';
}

/*********************************************************************
** Function: ~Wumpus
** Description: memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Wumpus::~Wumpus(){}

/*********************************************************************
** Function: get_message
** Description: return the message to the screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: message
*********************************************************************/ 
string Wumpus::get_message() {
    return message;
}

/*********************************************************************
** Function: get_alive
** Description: check the alive
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: alive
*********************************************************************/ 
bool Wumpus::get_alive() {
    return alive;
}