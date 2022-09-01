class Solution {
public:
    /*
    RECURSIVE APPROACH:
    TC:O(2^N) MORE THAN THAT BECOZ WE CAN TAKE COIN MULTIPLE TIMES
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)
            return 0;
        if(coins[0]>amount)
            return -1;
        int res = helper(coins,coins.size()-1,amount);
        if(res >= 1e9)
            return -1;
        return res;
    }
    int helper(vector<int>& coins , int ind , int amount){
        if(ind == 0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else 
                return 1e9;
        }
        int notTake = 0+helper(coins,ind-1,amount);
        int take = 1e9;
        if(amount>=coins[ind]){
            take = 1+helper(coins,ind,amount-coins[ind]);
        }
        return min(take,notTake);
    }
    */
    // MEMOIZED VERSION OF RECURSIVE APPROACH 
    // TC:O(N*T) where N size of coins and T is the target SC:O(N*T) + O(T)
    /*int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)
            return 0;
        if(coins[0]>amount)
            return -1;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int res = helper(coins,coins.size()-1,amount,dp);
        if(res >= 1e9)
            return -1;
        return res;
    }
    int helper(vector<int>& coins , int ind , int amount,vector<vector<int>>& dp){
        if(ind == 0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            else 
                return 1e9;
        }
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        int notTake = 0+helper(coins,ind-1,amount,dp);
        int take = 1e9;
        if(amount>=coins[ind]){
            take = 1+helper(coins,ind,amount-coins[ind],dp);
        }
        return dp[ind][amount] = min(take,notTake);
    }
    */
    // TABULATION
    // TC : O(N*T) SC: O(N*T)
    /*int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)
            return 0;
        if(coins[0]>amount)
            return -1;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // FEEDING THE TABLE WITH BASE CONDITIONS
        for(int t = 0 ; t<amount+1 ; t++){
            if(t%coins[0] == 0)
                dp[0][t] = t/coins[0];
            else
                dp[0][t] = 1e9;
        }
        int n = coins.size();
        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<=amount; target++){
                int notTake = 0 + dp[ind-1][target];
                int take = 1e9;
                if(coins[ind]<=target)
                    take = 1 + dp[ind][target - coins[ind]];

                 dp[ind][target] = min(notTake, take);
            }
    }
        return dp[n-1][amount]>=1e9 ? -1 : dp[n-1][amount];
    }    
    */
    // MORE SPACE DEDUCTION USING ONLY TWO ARRAYS
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)
            return 0;
        if(coins[0]>amount)
            return -1;
        vector<int> prev(amount+1,0) , curr(amount+1,0);
        // FEEDING THE TABLE WITH BASE CONDITIONS
        for(int t = 0 ; t<amount+1 ; t++){
            if(t%coins[0] == 0)
                prev[t] = t/coins[0];
            else
                prev[t] = 1e9;
        }
        int n = coins.size();
        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<=amount; target++){
                int notTake = 0 + prev[target];
                int take = 1e9;
                if(coins[ind]<=target)
                    take = 1 + curr[target - coins[ind]];

                 curr[target] = min(notTake, take);
            }
            prev = curr;
    }
        int ans = prev[amount];
        return ans>=1e9 ? -1 : ans;
    }
};