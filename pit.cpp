/*********************************************************************
** Program Filename: pit.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: pit implment
** Input: user inputs
** Output: set up two pits but in this file set up the objects
*********************************************************************/
#include "pit.hpp"
using namespace std;

/*********************************************************************
** Function: pit
** Description: Set up the pit message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Pit::Pit() {
    message = "You feel a breeze.";
    eventletter = 'p';
}

/*********************************************************************
** Function: ~pit
** Description: For the memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Pit::~Pit(){}

/*********************************************************************
** Function: get_message
** Description: return the message it has
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: message
*********************************************************************/ 
string Pit::get_message() {
    return message;
}