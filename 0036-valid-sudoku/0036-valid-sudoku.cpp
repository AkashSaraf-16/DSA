class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     unordered_map<char, int> mp;

        //checking row
     for(int i =0 ; i < board.size() ; i++){
         mp.clear();
         for(int j =0 ; j<board[0].size() ; j++){
             if(board[i][j] != '.'){
                 mp[board[i][j]]++;
                 if(mp[board[i][j]]>1)
                     return false;
             }
                 
         }
     }
        //checking column
     for(int i =0 ; i < board.size() ; i++){
         mp.clear();
         for(int j =0 ; j<board[0].size() ; j++){
             if(board[j][i] != '.'){
                 mp[board[j][i]]++;
                 if(mp[board[j][i]]>1)
                     return false;
             }
         }
     }
        // checking 3x3 grid
     for (int i = 0 ; i < board.size() ; i=i+3){
         for(int j = 0 ; j < board[0].size(); j=j+3){
             mp.clear();
             for(int k=i ; k<i+3 ; k++){
                 for(int l=j ; l< j+3 ; l++){
                     if(board[k][l] != '.'){
                         mp[board[k][l]]++;
                         if(mp[board[k][l]]>1)
                             return false;
                         
                     }
                 }
             }
        }
     }
    
        return true;
        
    }
};