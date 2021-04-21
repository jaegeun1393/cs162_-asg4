/*********************************************************************
** Program Filename: event.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: set the space to store other events
** Input: user inputs
** Output: Set up event in each room
*********************************************************************/

#include "event.hpp"
using namespace std;

/*********************************************************************
** Function: event
** Description:  make the space for the message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Event::Event() {
    message = " ";
    eventletter = ' ';
}

/*********************************************************************
** Function: ~Event
** Description: prevent event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Event::~Event() {}

/*********************************************************************
** Function: get_message
** Description: return message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
string Event::get_message() {
    return message;
}

/*********************************************************************
** Function: output_message
** Description: return message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Event::output_message() {
    cout << message << endl;
}