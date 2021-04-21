/*********************************************************************
** Program Filename: pit.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: wumpus implment
** Input: user inputs
** Output: pit message
*********************************************************************/
#ifndef PIT
#define PIT
using namespace std;
#include "event.hpp"

class Pit : public Event {
    protected:
        string message;
    public:
        Pit();
        ~Pit();
        string get_message();
};

#endif