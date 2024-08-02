class Board{
    vector<vector<char>> board;
    vector<vector<char>> hidden_board;
    int rows,cols;
    int number_of_mines;
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
    vector<pair<int,int>> mine_cell;
    bool valid(int r,int c,int& init_r,int& init_c){
        // The cell will be valid if the cell is not within the 1 unit range of the 8 directions of the initial cell
        if(r==init_r && c==init_c) return false;
        for(int i=0;i<8;i++){
            int cell_row = init_r+directions[i].first;
            int cell_col = init_c+directions[i].second;
            if(cell_row<0 || cell_col<0 || cell_row>=rows || cell_col>=cols) continue;
            if(r==cell_row && c==cell_col) return false;
        }
        return true;
    }
    void getMines(int init_r,int init_c){
        srand(time(0)); // This makes sure that the random numbers generated are different each time the program is run
        // We generate a cell for each mine
        for(int i=0;i<number_of_mines;i++){
            int mine_row = rand()%rows;
            int mine_col = rand()%cols;
            // we keep generating the row and col for mines until we get a cell which is a space , and it is a valid cell.
            while(board[mine_row][mine_col]!='#' || !valid(mine_row,mine_col,init_r,init_c)){
                mine_row = rand()%rows;
                mine_col = rand()%cols;
            }
            mine_cell.push_back({mine_row,mine_col});
            board[mine_row][mine_col] = 'M';
        }
    }
    void flag(int r,int c,int& flags){
        if(hidden_board[r][c]=='.'){
             hidden_board[r][c] = 'F';
             flags--;
        }else if(hidden_board[r][c]=='F'){
            hidden_board[r][c] = '.';
            flags++;
        }
    }
    void open(int r,int c){
        hidden_board[r][c] = board[r][c];
        if(board[r][c]!='#') return ;
        for(int i=0;i<8;i++){
            int cell_row = r+directions[i].first;
            int cell_col = c+directions[i].second;
            if(cell_row<0 || cell_col<0 || cell_row>=rows || cell_col>=cols || board[cell_row][cell_col]=='M') continue;
            if(hidden_board[cell_row][cell_col]=='.' && board[cell_row][cell_col]=='#'){
                open(cell_row,cell_col);
            }else{
                hidden_board[cell_row][cell_col] = board[cell_row][cell_col];
            }
        }
    }
    void fillValues(int r,int c){
        for(int i=0;i<8;i++){
            int cell_row = r+directions[i].first;
            int cell_col = c+directions[i].second;
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
    bool allMinesCovered(){
        for(auto c:mine_cell){
            if(hidden_board[c.first][c.second]!='F') return false;
        }
        return true;
    }
    void initialize(int init_r,int init_c){
        getMines(init_r,init_c);
        fillBoard();
        open(init_r,init_c);
    }
    int valid_move(int r,int c,int op,int& flags){
        if(r<0 || c<0 || r>=rows || c>=cols) return 0;
        if(op==1){
            if(flags>0 && hidden_board[r][c]=='F' || hidden_board[r][c]=='.'){
                flag(r,c,flags);
                return 1;
            }
        }else if(op==0){
            if(board[r][c]=='M') return -1;
            open(r,c);
        }
        return 0;
    }
    void UncoverMines(){
        for(auto c:mine_cell){
            hidden_board[c.first][c.second] = board[c.first][c.second];
        }
    }
};