#include <iostream>
#include<vector>
#include<cstdlib>
using namespace std;
class Board{
    vector<vector<char>> board;
    void fillMines(int number_of_mines){
        // We generate a cell for each mine
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<number_of_mines;i++){
            int mine_row = rand()%rows;
            int mine_col = rand()%cols;
            while(board[mine_row][mine_col]!='#'){
                mine_row = rand()%rows;
                mine_col = rand()%cols;
            }
            board[mine_row][mine_col] = 'M';
        }
    }
    void fillBoard(){
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='M'){
                    
                }
            }
        }
    }
    public:
    Board(int n,int m){
        // '#' -> Space
        // Initialize the board with spaces , we can fill these spaces with numbers
        board = vector<vector<char>>(n,vector<char>(m,'#'));
    }
};
int main(){
    
}