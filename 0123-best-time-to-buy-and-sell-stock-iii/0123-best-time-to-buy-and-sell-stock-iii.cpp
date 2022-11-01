class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(3,0)));
        // dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 0;
        // for(int i = 0 ; i<=n ; i++)
        //     dp[i][0][0] = dp[i][1][0] = 0;
        // BOTTOMUP DP
        for(int i = n-1 ; i >= 0 ; i--){
            for(int b = 0 ; b<=1 ; b++){
                for(int j = 1 ; j<=2 ; j++){
                    if(b)
                    dp[i][b][j] = max(-prices[i]+dp[i+1][0][j],dp[i+1][1][j]);
                    else
                    dp[i][b][j] = max(prices[i]+ dp[i+1][1][j-1],dp[i+1][0][j]);
                }
            }
        }
        return dp[0][1][2];
         // return helper(prices,0,1,2);            // RECUSIVE
        // return helper(prices,0,1,2,dp);          // TOPDOWN APPROACH
    }
    /*
    RECURSIVE
    int helper(vector<int> &p , int ind , int buy , int cap){
        if(ind == p.size() || cap == 0)
            return 0;
        int profit = 0;
        if(buy)
            profit = max(-p[ind]+helper(p,ind+1,0,cap),helper(p,ind+1,1,cap));
        else
            profit = max(p[ind]+helper(p,ind+1,1,cap-1),helper(p,ind+1,0,cap));
        return profit;
    }
    */
    /*
    TOPDOWN APPROACH
    int helper(vector<int> &p , int ind , int buy , int cap , vector<vector<vector<int>>> &dp){
        if(ind == p.size() || cap == 0)
            return 0;
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if(buy)
            return 
            dp[ind][buy][cap] = max(-p[ind]+helper(p,ind+1,0,cap,dp),helper(p,ind+1,1,cap,dp));
        return
            dp[ind][buy][cap] = max(p[ind]+helper(p,ind+1,1,cap-1,dp),helper(p,ind+1,0,cap,dp));
    }
    */
        
};