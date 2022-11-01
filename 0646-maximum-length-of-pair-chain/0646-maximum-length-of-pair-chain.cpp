class Solution {
    int n;
public:
    int rec(int curr, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp){
        if(curr == n)   return 0;
        
        if(dp[curr][prev+1] != -1)  return dp[curr][prev+1];
        int take = 0;
        
        if(prev == -1 or pairs[prev][1] < pairs[curr][0])   take = 1 + rec(curr+1, curr, pairs, dp);
        int nontake = rec(curr+1, prev, pairs, dp);
        
        return dp[curr][prev+1] = max(take, nontake);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return rec(0, -1, pairs, dp);
    }
};