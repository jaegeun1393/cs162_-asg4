/*********************************************************************
** Program Filename: Bats.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: Object for Bats
** Input: BAts
** Output: Bats message
*********************************************************************/
#ifndef BATS
#define BATS
using namespace std;
#include "event.hpp"

class Bats : public Event{
	protected:
		string message;
	public:	
		Bats();
		~Bats();
		string get_message();
		void output_message();
};

#endif


