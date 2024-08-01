#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Game.h"

int main(){
    srand(time(0)); // This makes sure that the random numbers generated are different each time the program is run
    Game game(0);
    game.start_game();
}