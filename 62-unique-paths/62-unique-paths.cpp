class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0 ; j<n ; j++)
            dp[0][j] = 1;
        for(int j=0 ; j<m ; j++)
            dp[j][0] = 1;
        for(int i = 1 ;i<m ; i++){
            for(int j = 1 ; j<n ; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
    int helper(int m , int n){
        if(m == 1 || n == 1) // since we can reach 1st row/column in only one way
            return 1;
        int res = helper(m-1,n) + helper(m,n-1);
        return res;
    }
};