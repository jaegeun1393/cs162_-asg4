/*********************************************************************
** Program Filename: Hunt_Wumpus.cpp
** Author: jaegeun oh
** Date: 3/4/2019
** Description: Let's hunt wumpus!
** Input: user inputs
** Output: Set up the game and run
*********************************************************************/
#include<iostream>
#include<cstdlib>
#include"game.hpp"
using namespace std;

/*********************************************************************
** Function: main
** Description: make the game object and double check the number is more than 4
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
int main(int argc, char*argv[]) {
	Game game1;
	int size = 0;
	size = atoi(argv[1]);
	if(size < 4) {
		cout << "You must have more than 4." << endl;
	} else {
		system("clear");
		cout << "HUNT THE WUMPUS! START!" << endl;
		game1.start_game(size);
	}

	return 0;
}
