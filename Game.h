#include "Board.h"
class Game{
    Board* board;
    int flags;
    void game_over(){
        cout << "GAME OVER!!!!" << endl;
    }
    void win(){
        cout << "CONGRATS! YOU WON" << endl;
    }
    public:
    Game(int difficulty){
        if(difficulty==0){
            board = new Board(9,9,10);
            flags = 10;
        }else if(difficulty==1){
            board = new Board(16,16,40);
            flags = 40;
        }else{
            board = new Board(30,16,99);
            flags = 99;
        }
        board->display();
    }
    void start_game(){
        int init_r,init_c;
        cout << "Choose a cell to start : ";
        cin >> init_r >> init_c;
        board->initialize(init_r,init_c);
        board->display();
        // board->hidden_display();
        // while(!board->game_over() && flags!=0){
        //     board->display();
        //     cout << "Choose a cell : ";
        //     cin >> init_r >> init_c;
        //     cout << "Do you want to flag(1) or open(0) : ";
        //     int op;
        //     cin >> op;
        //     board->move(init_r,init_c,op);
        //     if(op) flags--;
        // }
        game_over();
    }
    
};