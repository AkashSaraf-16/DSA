class Solution {
public:
    // TC : O(N*M) SC: O(N*M)
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int res = 0;
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[0].size() ; j++){
                if(i == 0 || j == 0){
                    if(matrix[i][j] == '1')
                        dp[i][j] = 1;
                }
                else{
                    // if this cell is 1 checking whether its surrounding
                    if(matrix[i][j] == '1'){
                        dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                    }
                }
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};