class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //return recur(prices,0,1);
        //return mem(prices,0,1,dp);
        // STEP 3 : DP
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        dp[n+1][0] = dp[n+1][1] = dp[n][0] = dp[n][1] = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
            dp[i][0] = max(prices[i]  + dp[i+2][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
    /*
    STEP 2 : TOP DOWN(MEMOIZATION)
    int mem(vector<int> &p , int ind , int buy, vector<vector<int>> dp){
        if(ind>=p.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-p[ind] + mem(p,ind+1,0,dp),mem(p,ind+1,1,dp));
        }
        else{
            profit = max(p[ind]  + mem(p,ind+2,1,dp),mem(p,ind+1,0,dp));
        }
        return dp[ind][buy] = profit;        
    }
    */
    /*
    STEP 1 : RECURSIVE APPROACH:
    int recur(vector<int> &p , int ind , int buy){
        if(ind>=p.size())
            return 0;
        
        int profit = 0;
        if(buy){
            profit = max(-p[ind] + recur(p,ind+1,0),recur(p,ind+1,1));
        }
        else{
            profit = max(p[ind]  + recur(p,ind+2,1),recur(p,ind+1,0));
        }
        return profit;
    }*/
};