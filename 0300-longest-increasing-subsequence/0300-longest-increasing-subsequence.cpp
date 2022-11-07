// RECURSIVE APPROACH:
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums,0,-1);
    }
    int helper(vector<int> &n , int ind , int prev_ind){
        if(ind == n.size())
            return 0;
        
        int len = helper(n,ind+1,prev_ind);
        if(prev_ind == -1 || n[ind]>n[prev_ind]){
            len = max (len , 1+helper(n,ind+1,ind));
        }
        return len;
    }
};*/
// Top-Down DP
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
    int helper(vector<int> &n , int ind , int prev_ind , vector<vector<int>> &dp){
        if(ind == n.size())
            return 0;
        if(dp[ind][prev_ind+1] != -1)
            return dp[ind][prev_ind+1];
        int len = helper(n,ind+1,prev_ind,dp);
        if(prev_ind == -1 || n[ind]>n[prev_ind]){
            len = max (len , 1+helper(n,ind+1,ind,dp));
        }
        return dp[ind][prev_ind+1] = len;
    }
};
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // contains len of longest subseq between curr index and prev_ind
        for(int ind = n-1 ; ind>=0 ; ind--){
            for(int prev_ind = ind-1 ; prev_ind>=-1 ; prev_ind--){  // here prev_ind is -1 but we cant have -1 as index hence we will replace prev_ind->prev_ind+1
                int len = dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
                    len = max (len , 1+dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1] = len;               
            }
        }
        return dp[0][0];
    }
};      