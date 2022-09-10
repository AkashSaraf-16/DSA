class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xno = 0,ono = 0;
        for(int i =0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(board[i][j] == 'X')  xno++;
                else if(board[i][j] == 'O') ono++;
            }
        }
        if(!(xno == ono || xno == ono+1))    return false;
        else if(xno == ono){
            return !isWin(board,'X');       // if no. of 'X' is equal to no. of 'O' then X cant win 
        }
        else{
            return !isWin(board,'O');       // if no. of 'X' is equal to no. of 'O' + 1 then O cant win
        }
        return true;
    }
    bool isWin(vector<string>& board , char c){
        for(int i = 0 ; i < 3 ; i++){       // checking the row and columns
            if(board[i][0] == c  && board[i][1] == c && board[i][2] == c){
                return true;
            }
            else if(board[0][i] == c && board[1][i] == c && board[2][i] == c){
                return true;
            }
        }
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c){ // checking the diagonal
            return true;
        }
        else if(board[0][2] == c && board[1][1] == c && board[2][0] == c){ // checking the diagonal
            return true;
        }
        return false;
    }
};