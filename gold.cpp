/*********************************************************************
** Program Filename: gold.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: gold implment
** Input: user inputs
** Output: set up the gold object
*********************************************************************/
#include "gold.hpp"
using namespace std;

/*********************************************************************
** Function: gold
** Description: Set up the gold message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Gold::Gold() {
	message = "You See a glimmer nearby";
	eventletter = 'g';
}

/*********************************************************************
** Function: gold
** Description: prevent memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Gold::~Gold() {}

/*********************************************************************
** Function: get_message
** Description: Set up the gold message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
string Gold::get_message() {
	return message;
}
