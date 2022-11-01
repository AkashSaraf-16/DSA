class Solution {
public:
    //RECURSIVE APPROACH:
    //TC: O(2^M*N)
    /*int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        return helper(grid,r-1,c-1);
    }
    int helper(vector<vector<int>> &g , int row , int col){
        if(row == 0 || col == 0){
            if(row == 0){
                int rsum = 0;
                for(int i = 0 ; i<=col ; i++)
                    rsum+= g[0][i];
            return rsum;
            }
            if(col == 0){
                int csum = 0;
                for(int i = 0 ; i<=row ; i++)
                    csum+= g[i][0];
            return csum;               
            }  
        }
        
        int up = helper(g,row-1,col);
        int left = helper(g,row,col-1);
        return g[row][col]+min(up,left);
    }
    */\
    // MEMOIZED TOP DOWN APPROACH
    // TC : O(M*N) SC:O(M*N)
    /*
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return helper(grid,r-1,c-1,dp);
    }
    int helper(vector<vector<int>> &g , int row , int col , vector<vector<int>> &dp){
        if(row == 0 || col == 0){
            if(row == 0){
                int rsum = 0;
                for(int i = 0 ; i<=col ; i++)
                    rsum+= g[0][i];
            return rsum;
            }
            else{
                int csum = 0;
                for(int i = 0 ; i<=row ; i++)
                    csum+= g[i][0];
            return csum;               
            }
        }
        if(dp[row][col]!= -1)
            return dp[row][col];
        int up = helper(g,row-1,col,dp);
        int left = helper(g,row,col-1,dp);
        return dp[row][col] = g[row][col]+min(up,left);
    }
    */
    // TABULATION BOTTOM UP APPROACH:
    // TC:O(M*N) SC:(M*N)
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int rsum = 0 , csum = 0;
        for(int i = 0 ; i<c ; i++){
            rsum+= grid[0][i];
            dp[0][i] = rsum;
        }
        for(int i = 0 ; i<r ; i++){
            csum+= grid[i][0];
            dp[i][0] = csum;
        }
        for( int row = 1 ; row<r ; row++){
            for(int col = 1 ; col<c ; col++){
                int up = dp[row-1][col];
                int left = dp[row][col-1];
                dp[row][col] = grid[row][col]+min(up,left);
            }
        }
        return dp[r-1][c-1];
    }
};