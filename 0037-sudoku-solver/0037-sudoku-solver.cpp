class Solution {
public:
    bool isValid(vector<vector<char>> board , int row , int col , char c){
        for(int k = 0 ; k < 9 ; k++){
            if(board[k][col] == c)
                return false;
            if(board[row][k] == c)
                return false;
            if(board[3*(row/3) + k/3][3*(col/3) + k%3] == c)
                return false;
        }
        return true;
    }
    bool solver(vector<vector<char>>& board){
        for(int i = 0 ; i< 9 ; i++){
            for(int j = 0 ;j < 9 ; j++){
                if(board[i][j] == '.'){         // checking if empty cell can be filled or not
                    for(char c = '1' ; c <= '9' ; c++){
                    if(isValid(board,i,j,c) == true){       // if yes then feed the value
                        board[i][j] = c;
                        if(solver(board))                // and call recursion on the board
                            return true;
                        else
                            board[i][j] = '.' ;      // if not able to fill backtrack
                        }
                    }
                    return false;       // if we cant fill any value from 1-9
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};