class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy){                // if we can buy
                    profit = max((-prices[ind]) + dp[ind+1][false],dp[ind+1][true]);
                                                    //      take(buy)               not take(not buy)
                }
                else                    // if we can sell
                    profit = max((prices[ind]) + dp[ind+1][true],dp[ind+1][false]); 
                                                    //      sell                    // not sell
                dp[ind][buy]=profit;                
            }
        }
        return dp[0][1];
    }
};