/*class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,vector<vector<string>> &ans,int n){
        int duprow = row;
        int dupcol = col;
        while(col>=0){      // checking the left rows
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row>=0 && col>=0){  // checking upper left diagonal
            if(board[row][col] == 'Q')
                return false;
            row--;          
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){     // checking the lower right diagonal
            if(board[row][col] == 'Q')
                return false;
            row++;          
            col--;           
        }
        return true;
    }
    void solver(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0  ; row<n ; row++){
            if(isSafe(row,col,board,ans,n)){
                board[row][col] = 'Q';
                solver(col+1,board,ans,n);
                board[row][col] = '.';      // backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0 ; i < n ; i++)
            board[i] = s;
        solver(0,board,ans,n);
        return ans;
    }
};
*/
class Solution {
public:
    void solver(int col, vector<string> &board, vector<vector<string>> &ans,vector<int> &leftrow,vector<int> &upperdiagonal , vector<int> &lowerdiagonal , int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0  ; row<n ; row++){
            if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0){
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1+col-row] = 1;
                board[row][col] = 'Q';
                solver(col+1, board, ans, leftrow, upperdiagonal, lowerdiagonal, n);
                board[row][col] = '.';      // backtracking
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0 ; i < n ; i++)
            board[i] = s;
        vector<int> leftrow(n,0) , upperdiagonal(2*n-1, 0) , lowerdiagonal(2*n-1, 0); 
        solver(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
        return ans;
        
    }
};