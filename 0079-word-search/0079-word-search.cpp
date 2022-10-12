class Solution {
public:
// TC:O(M*N*L^4)  SC:O(M*N)
    bool DFS(vector<vector<char>>& board, string &word, int r, int c, int index, vector<vector<bool>> &vis){
        if(index == word.length())
            return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || vis[r][c] || word[index]!=board[r][c]){
            return false;
        }
        vis[r][c] = true;
        bool res= DFS(board,word,r+1,c,index+1,vis)||DFS(board,word,r,c+1,index+1,vis)||DFS(board,word,r-1,c,index+1,vis)||DFS(board,word,r,c-1,index+1,vis);
        vis[r][c] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //DFS based approach
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        if(col==0)
            return false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(DFS(board,word,i,j,0,vis))                 //(board,word,x,y,index)
                    return true;
            }
        }
        return false;
    }
};