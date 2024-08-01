class Board{
    vector<vector<char>> board;
    vector<vector<char>> hidden_board;
    int rows,cols;
    int number_of_mines;
    bool valid(int r,int c,int& init_r,int& init_c){
        if(r==init_r && c==init_c) return false;
        int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
        for(int i=0;i<8;i++){
            int cell_row = init_r+directions[i][0];
            int cell_col = init_c+directions[i][1];
            if(cell_row<0 || cell_col<0 || cell_row>=rows || cell_col>=cols) continue;
            if(r==cell_row && c==cell_row) return false;
        }
        return true;
    }
    void getMines(int init_r,int init_c){
        // We generate a cell for each mine
        for(int i=0;i<number_of_mines;i++){
            int mine_row = rand()%rows;
            int mine_col = rand()%cols;
            while(board[mine_row][mine_col]!='#' || !valid(mine_row,mine_col,init_r,init_c)){
                mine_row = rand()%rows;
                mine_col = rand()%cols;
            }
            board[mine_row][mine_col] = 'M';
        }
    }
    void flag(int r,int c){
        hidden_board[r][c] = 'F';
    }
    void open(int r,int c){
        int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
        hidden_board[r][c] = board[r][c];
        for(int i=0;i<8;i++){
            int cell_row = r+directions[i][0];
            int cell_col = c+directions[i][1];
            if(cell_row<0 || cell_col<0 || cell_row>=rows || cell_col>=cols || board[cell_row][cell_col]=='M') continue;
            if(hidden_board[cell_row][cell_col]=='.' && board[cell_row][cell_col]=='#'){
                open(cell_row,cell_col);
            }else{
                hidden_board[cell_row][cell_col] = board[cell_row][cell_col];
            }
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
    
    public:
    Board(int m,int n,int mines){
        // '#' -> Space
        // Initialize the board with spaces , we can fill these spaces with numbers
        board = vector<vector<char>>(m,vector<char>(n,'#'));
        hidden_board = vector<vector<char>>(m,vector<char>(n,'.'));
        rows = m;
        cols = n;
        this->number_of_mines = mines; 
    }
    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << hidden_board[i][j] << " ";
            }
            cout << endl;
        }
    }
    void hidden_display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool game_over(){
        return false;
    }
    void initialize(int init_r,int init_c){
        getMines(init_r,init_c);
        fillBoard();
        open(init_r,init_c);
    }
    void move(int r,int c,int op){
        if(op){
            flag(r,c);
        }else{
            open(r,c);
        }
    }
    
};