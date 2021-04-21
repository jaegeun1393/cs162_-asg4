/*********************************************************************
** Program Filename: Wumpus.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: Wumpus
** Input: user inputs
** Output: wumpus location
*********************************************************************/
#ifndef WUMPUS
#define WUMPUS

#include "event.hpp"
using namespace std;

class Wumpus : public Event {
    protected:
        string message;
        bool alive;
    public:
        Wumpus();
        ~Wumpus();
        string get_message();
        bool get_alive();
};

#endif