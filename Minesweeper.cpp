#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
#include "Board.h"

int main(){
    srand(time(0));
    Board board(9,9);
    board.setup();
}