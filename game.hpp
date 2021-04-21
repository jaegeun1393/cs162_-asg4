/*********************************************************************
** Program Filename: game.hpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: wumpus implment
** Input: user inputs
** Output: Basic Game
*********************************************************************/

#ifndef _GAME
#define _GAME

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include "room.hpp"

using namespace std;

class Game : Room{
    protected:
        Room **rooms; // double cause of the array
        int gridsize, arrows, numGold;
        int startx, starty, currentx, currenty, action, player_action, wumpusx, wumpusy;
        string movement;
        bool gameover, won, wumpus_dead, again;
    
    public:
        Game(); 
        ~Game(); 
        void start_game(int num); 

        //set the game
        void set_gridsize(); 
        void set_room(); 
        void set_event_in_room(); 
        int set_random_position(); 
        void output_grid(); 

        //player action
        void set_move(); 
        string get_move(); 
        void out_of_arrow(); 
        void get_player_action(); 
        void move_player(); 
        void shoot_arrow(); 

        //statu of the game
        bool get_won(); 
        bool inbounds(int x, int y); 
        void check_event(); 
        void win_the_game(); 
        void end_game(); 
        void menu(); 
        void out_put_message(); 
        void set_start_position(); 

        //header ai system
        //void AI();

};

#endif