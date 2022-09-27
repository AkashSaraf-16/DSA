class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(prices,0,true,dp);
    }
    int helper(vector<int> &prices , int ind , bool buy , vector<vector<int>> &dp){
        if(ind == prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        // Getting the recurrence relation
        // exploring every possibilities
        int profit = 0;
        if(buy){                // if we can buy
            profit = max((-prices[ind]) + helper(prices,ind+1,false,dp),helper(prices,ind+1,true,dp)); 
                                            //      take(buy)               not take(not buy)
        }
        else                    // if we can sell
            profit = max((prices[ind]) + helper(prices,ind+1,true,dp),helper(prices,ind+1,false,dp)); 
                                            //      sell                    // not sell
        return dp[ind][buy]=profit;
    }
};