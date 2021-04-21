/*********************************************************************
** Program Filename: event.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: wumpus implment
** Input: user inputs
** Output: event containing information
*********************************************************************/
#ifndef EVENT
#define EVENT
#include<iostream>
using namespace std;

class Event {
    protected:
        int locationx, locationy;
        string message;
        char eventletter;
    public:
        Event();
        ~Event();
        virtual string get_message();
        virtual void output_message();
};

#endif