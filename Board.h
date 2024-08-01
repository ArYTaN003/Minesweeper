class Board{
    vector<vector<char>> board;
    int rows,cols;
    void fillMines(int number_of_mines){
        // We generate a cell for each mine
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
    void fillValues(int r,int c){
        int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
        for(int i=0;i<8;i++){
            int cell_row = r+directions[i][0];
            int cell_col = c+directions[i][1];
            if(cell_row<0 || cell_col<0 || cell_row>=rows || cell_col>=cols || board[cell_row][cell_col]=='M') continue;
            if(board[cell_row][cell_col]=='#'){
                board[cell_row][cell_col] = '1';
            }else{
                board[cell_row][cell_col] = '0'+((board[cell_row][cell_col]-'0')+1);
            }
        }
    }
    void fillBoard(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='M'){
                    fillValues(i,j);   
                }
            }
        }
    }
    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    public:
    Board(int m,int n){
        // '#' -> Space
        // Initialize the board with spaces , we can fill these spaces with numbers
        board = vector<vector<char>>(m,vector<char>(n,'#'));
        rows = m;
        cols = n;
    }
    
    void setup(){
        fillMines(10);
        fillBoard();
        display();
    }
};