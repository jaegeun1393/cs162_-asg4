/*********************************************************************
** Program Filename: bats.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: bats implment
** Input: user inputs
** Output: Set up the bat object
*********************************************************************/

#include "bats.hpp"
using namespace std;

/*********************************************************************
** Function: Bats
** Description: Set up the bat message and the logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Bats::Bats() {
	message = "you hear wings flapping.";
	eventletter = 'b';
}

/*********************************************************************
** Function: ~Bats
** Description: prevent memory leak
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Bats::~Bats(){}

/*********************************************************************
** Function: get_message
** Description: return message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
string Bats::get_message() {
	return message;
}

/*********************************************************************
** Function: output_message
** Description: print out the message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Bats::output_message() {
    cout << message << endl;
}