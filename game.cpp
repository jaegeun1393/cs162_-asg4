#include "game.hpp"
#include<string>
#include<vector>
using namespace std;

/*********************************************************************
** Function: Game
** Description: set the basic information to start the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Game::Game() {
    gridsize = 0;
    arrows = 3;
    numGold = 0;
    startx = 0, starty = 0, currentx = 0, currenty = 0, wumpusx = 0, wumpusy = 0;
    action = 0;
    movement = ' ';
    gameover = false, won = false, wumpus_dead = false, again = false;
}

/*********************************************************************
** Function: ~Game
** Description: prevent memory leak issue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Game::~Game() {
    for(int i = 0; i < gridsize; i++) {
        delete [] rooms[i];
    }
    delete [] rooms; 
}

/*********************************************************************
** Function: set_gridsize
** Description: set the size of the grid when the user failed
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::set_gridsize() {
    cout << "Enter the grid size: ";
    cin >> gridsize;
}

/*********************************************************************
** Function: set_room
** Description: setting rooms to start the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::set_room() {
   /* vector<vector<Room> > rooms(gridsize, vector<Room>(gridsize));     
    
    vector<vector<Room> > rooms;
    rooms = vector<vector <Room> > (gridsize, vector<Room>(gridsize));*/
    rooms = new Room*[gridsize];
    for(int i = 0; i < gridsize; i++) {
        rooms[i] = new Room[gridsize];
    } 
}

/*********************************************************************
** Function: set_move
** Description: ask what movement player want to have
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::set_move() {
    bool again = true;
    while(again) {
        cout << "Enter up, left, right, or down: ";
        getline(cin, movement);
        if(movement == "up" || movement == "down" || movement == "right" || movement == "left") {
            again = false;
        }
    }
}

/*********************************************************************
** Function: set_random_position
** Description: give the random int
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: rand_position
*********************************************************************/ 
int Game::set_random_position() {
    int num = rand() % gridsize;
    return num;
}

/*********************************************************************
** Function: set_evnet_in_room
** Description: set the event in each room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::set_event_in_room() {
    bool again = true;
    int x = 0, y = 0, i = 0;
    rooms[startx][starty].set_event('x');
    while(again) {
        x = set_random_position();
        y = set_random_position();
        if((rooms[x][y].get_event() == ' ') && (i == 0)) {
            rooms[x][y].set_event('g');
            i++;
        }
        else if((rooms[x][y].get_event() == ' ') && (i == 1)) {
            rooms[x][y].set_event('p');
            i++;
        }
        else if((rooms[x][y].get_event() == ' ') && (i == 2)) {
            rooms[x][y].set_event('p');
            i++;
        }
        else if((rooms[x][y].get_event() == ' ') && (i == 3)) {
            rooms[x][y].set_event('b');
            i++;
        }
        else if((rooms[x][y].get_event() == ' ') && (i == 4)) {
            rooms[x][y].set_event('b');
            i++;
        }
        else if((rooms[x][y].get_event() == ' ') && (i == 5)) {
            rooms[x][y].set_event('w');
            wumpusx = x;
            wumpusy = y;
            i++;
            again = false;
        }
    }
}

/*********************************************************************
** Function: out_put_message
** Description: printing out the message from the specific event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::out_put_message() {
    //left
    if ((inbounds(currentx, currenty-1) == true) && (rooms[currentx][currenty-1].get_event() != ' ')) {
		cout << rooms[currentx][currenty-1].get_message() << endl;
	}
	
	//down
	if ((inbounds(currentx+1, currenty) == true) && (rooms[currentx+1][currenty].get_event() != ' ')) {
		cout << rooms[currentx+1][currenty].get_message() << endl;
	}
	 
	//up
	if ((inbounds(currentx-1, currenty) == true) && (rooms[currentx-1][currenty].get_event() != ' ')) {
		cout << rooms[currentx-1][currenty].get_message() << endl;
	}
	 
	//right
	if ((inbounds(currentx, currenty+1) == true) && (rooms[currentx][currenty+1].get_event() != ' ')) {
		cout << rooms[currentx][currenty+1].get_message() << endl;
	}
}

/*********************************************************************
** Function: set_start_position
** Description: set the starting position for the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::set_start_position() {
    startx = currentx = set_random_position();
    starty = currenty = set_random_position();
    cout << "Player start at: " << starty + 1 << " " << startx + 1 << endl;
}

/*********************************************************************
** Function: out_of_arrow
** Description: check the amount of arrow 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::out_of_arrow() {
    if(arrows <= 0) {
        cout << "|-You do not have any arrow!\n|-Wumpus eat you" << endl;
        gameover = true;
    } else {
        arrows--;
        shoot_arrow();
    }
}

/*********************************************************************
** Function: get_move
** Description: get the movement user entered
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
string Game::get_move() {
    return movement;
}

/*********************************************************************
** Function: get_won
** Description: check the user win the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Game::get_won() {
    return won;
}

/*********************************************************************
** Function: output_grid
** Description: printing out the grid from the map data
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::output_grid() {
    //draw_top
    for(int i = 0; i < gridsize; i++) {
        cout << "+";
        for(int j = 0; j < gridsize; j++) { //deco
            cout<< "---+";
        }
        cout << endl;
        for(int k = 0; k < 3; k++) {
            cout << "|";
            for(int l = 0; l < gridsize; l++) {
                if(rooms[i][l].get_event() == 'x') {
                    cout <<" x |";
                }
                else if((rooms[i][l].get_event() == 'w') && (wumpus_dead == false)) {
                    cout << " w |";
                }
                else if(rooms[i][l].get_event() == 'p') {
                    cout << " p |";
                }
                else if(rooms[i][l].get_event() == 'b') {
                    cout << " b |";
                }
                else if(rooms[i][l].get_event() == 'g') {
                    cout << " g |";
                }
                else {
                    cout << "   |";
                }
            }
            cout << endl;
        }
    }
    cout << "+";
    for(int j = 0; j < gridsize; j++) {
        cout<< "---+";
    }
}

/*********************************************************************
** Function: get_player_action
** Description: get the action from the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::get_player_action() {
    bool again = true;
    string user_input;
    while(again) {
        cout << "Would you like to 1.move or 2.attack?: ";
        getline(cin, user_input);
        if(user_input == "1") {
            player_action = 1;
            again = false;
            } 
        else if(user_input == "2") {
                player_action = 2;
                again = false;
            }
    }
    cin.clear();
}

/*********************************************************************
** Function: move_player
** Description: check the player move location is moveable
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::move_player() {
    if((movement == "up") && (inbounds(currentx-1, currenty) == true)) {
        rooms[currentx][currenty].set_event(' ');
        currentx --;
        check_event();
        rooms[currentx][currenty].set_event('x');
    }
    else if((movement == "down") && (inbounds(currentx+1, currenty) == true)) {
        rooms[currentx][currenty].set_event(' ');
        currentx ++;
        check_event();
        rooms[currentx][currenty].set_event('x');
    }
    else if((movement == "left") && (inbounds(currentx, currenty-1) == true)) {
        rooms[currentx][currenty].set_event(' ');
        currenty --;
        check_event();
        rooms[currentx][currenty].set_event('x');
    }
    else if((movement == "right") && (inbounds(currentx, currenty+1) == true)) {
        rooms[currentx][currenty].set_event(' ');
        currenty ++;
        check_event();
        rooms[currentx][currenty].set_event('x');
    }
    else {
        cout << "|-You are out of bounce!" << endl;
    }
}

/*********************************************************************
** Function: shoot_arrow
** Description: check the wall present and shooting the arrow
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::shoot_arrow() {
    set_move();
    bool again = true;
    int tempx, tempy, awake, x, y;
    if(movement == "right") {
        for(int i = 1; i <=3; i++) {
            tempx = currentx;
            tempy = currenty + i;
            if((inbounds(tempx, tempy) == true) && (rooms[tempx][tempy].get_event() == 'w')) {
                cout << "|-You killed Wumpus!" << endl;
                wumpus_dead = true;
                i = 5;
            } else {
                awake = rand()%100;
                if(inbounds(tempx, tempy) == true) {
                cout << "|-Nothing Happen" << endl; } else {
                    cout << "|-Arrow hits the wall" << endl;
                    i = 3;
                }
                if((awake <= 75) && (i == 3) && (wumpus_dead == false)) {
                    cout << "||-Wumpus awake, it randomly move.." << endl;
                    while(again) {
                        x = set_random_position();
                        y = set_random_position();
                        if(rooms[x][y].get_event() == ' ') {
                            rooms[wumpusx][wumpusy].set_event(' ');
                            rooms[x][y].set_event('w');
                            wumpusx = x;
                            wumpusy = y;
                            again = false;
                        }
                    }
                }
            again = true;
            }
        }   
    }

    else if(movement == "left") {
        for(int i = 1; i <=3; i++) {
            tempx = currentx;
            tempy = currenty - i;
            if((inbounds(tempx, tempy) == true) && (rooms[tempx][tempy].get_event() == 'w')) {
                cout << "|-You killed Wumpus!" << endl;
                wumpus_dead = true;
                i = 5;
            } else {
                awake = rand()%100;
                if(inbounds(tempx, tempy) == true) {
                cout << "|-Nothing Happen" << endl; } else {
                    cout << "|-Arrow hits the wall" << endl;
                    i = 3;
                }
                if((awake <= 75) && (i == 3) && (wumpus_dead == false)) {
                    cout << "||-Wumpus awake, it randomly move.." << endl;
                    while(again) {
                        x = set_random_position();
                        y = set_random_position();
                        if(rooms[x][y].get_event() == ' ') {
                            rooms[wumpusx][wumpusy].set_event(' ');
                            rooms[x][y].set_event('w');
                            wumpusx = x;
                            wumpusy = y;
                            again = false;
                        }
                    }
                }
            again = true;
            }     
        }   
    }

    else if(movement == "up") {
        for(int i = 1; i <=3; i++) {
            tempx = currentx - i;
            tempy = currenty;
            if((inbounds(tempx, tempy) == true) && (rooms[tempx][tempy].get_event() == 'w')) {
                cout << "|-You killed Wumpus!" << endl;
                wumpus_dead = true;
                i = 5;
            } else {
                awake = rand()%100;
                if(inbounds(tempx, tempy) == true) {
                cout << "|-Nothing Happen" << endl; } else {
                    cout << "|-Arrow hits the wall" << endl;
                    i = 3;
                }
                if((awake <= 75) && (i == 3) && (wumpus_dead == false)) {
                    cout << "||-Wumpus awake, it randomly move.." << endl;
                    while(again) {
                        x = set_random_position();
                        y = set_random_position();
                        if(rooms[x][y].get_event() == ' ') {
                            rooms[wumpusx][wumpusy].set_event(' ');
                            rooms[x][y].set_event('w');
                            wumpusx = x;
                            wumpusy = y;
                            again = false;
                        }
                    }
                }
            again = true;
            }
        }   
    }

    else if(movement == "down") {
        for(int i = 1; i <=3; i++) {
            tempx = currentx + i;
            tempy = currenty;
            if((inbounds(tempx, tempy) == true) && (rooms[tempx][tempy].get_event() == 'w')) {
                cout << "|-You killed Wumpus!" << endl;
                wumpus_dead = true;
                i = 5;
            } else {
                awake = rand()%100;
                if(inbounds(tempx, tempy) == true) {
                cout << "|-Nothing Happen" << endl; } else {
                    cout << "|-Arrow hits the wall" << endl;
                    i = 3;
                }
                if((awake <= 75) && (i == 3) && (wumpus_dead == false)) {
                    cout << "||-Wumpus awake, it randomly move.." << endl;
                    while(again) {
                        x = set_random_position();
                        y = set_random_position();
                        if(rooms[x][y].get_event() == ' ') {
                            rooms[wumpusx][wumpusy].set_event(' ');
                            rooms[x][y].set_event('w');
                            wumpusx = x;
                            wumpusy = y;
                            again = false;
                        }
                    }
                }
            again = true;
            }
        }   
    }
}

/*********************************************************************
** Function: check_event
** Description: check what event it located at the currentx and y
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::check_event(){
	if (rooms[currentx][currenty].get_event() == 'w' && wumpus_dead == false){
		cout << "|-Wumpus ate you.\nLose game... " << endl;
		gameover = true;
	} //wumpus
	else if (rooms[currentx][currenty].get_event() == 'b'){
		cout << "|-Player meet the bat, Bats carry you away!" << endl;
		rooms[currentx][currenty].set_event(' ');
		currentx = set_random_position();
		currenty = set_random_position();
		rooms[currentx][currenty].set_event('x');
	} //bats
	else if (rooms[currentx][currenty].get_event() == 'g'){
		cout << "|-You have found gold, congrats!" << endl;
		numGold++;
	} //Gold find
	else if (rooms[currentx][currenty].get_event() == 'p'){
		cout << "|-Player fallen in the pit..\nLose game" << endl;
		gameover = true;
	} //pit
}

/*********************************************************************
** Function: inbounds
** Description: check the tempx and y bounds are safe to move
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Game::inbounds(int x, int y) {
    if(x > gridsize-1 || y > gridsize-1 || x < 0 || y < 0) {
        return false;
    } else {
        return true;
    }
}

/*********************************************************************
** Function: menu
** Description: list of move or attack
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::menu() {
    get_player_action();
    if(player_action == 1) {
        set_move();
        move_player();
        check_event();
    }
    else if(player_action == 2) {
        out_of_arrow();
    }
}

/*********************************************************************
** Function: end_game
** Description: check the player win the game 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::end_game() {
    if (won == true && wumpus_dead == true) {
        cout << "THE PLAYER WIN THE GAME!" << endl;
    } else {
        cout << "GAME END" << endl;
    }
}

/*********************************************************************
** Function: win_the_game
** Description: when the player win the game then print out win the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::win_the_game() {
    if((currentx == startx) && (currenty == starty) && (numGold == 1) && (wumpus_dead == true)) {
        won = true;
        gameover = true;
    }
}

/*********************************************************************
** Function: start_game
** Description: start the game
** Parameters: int
** Pre-Conditions: num
** Post-Conditions: none
*********************************************************************/ 
void Game::start_game(int num) {
    if(again == true) {
        set_gridsize();
    }

    gridsize = num;
    set_room();
    set_start_position();
    set_event_in_room();
    output_grid();
    do{
        cout << "\n\n" << endl;
        cout <<"Gold found: " << numGold << endl;
        cout <<"Number of Arrow: " << arrows << endl;
        cout <<"Player's location: " << currenty + 1 << " : " << currentx + 1 << endl;

        out_put_message();
        menu();
        output_grid();
        win_the_game();
        if(arrows <= 0) {
            gameover = true;
            cout << endl;
        }
    } while(!gameover);
        end_game();

}