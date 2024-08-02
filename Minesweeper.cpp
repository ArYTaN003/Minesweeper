#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Game.h"

int main(){
    cout << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl <<  "Choose a difficulty : ";
    int difficulty;
    cin >> difficulty;
    Game game(difficulty-1);
    game.start_game();
}