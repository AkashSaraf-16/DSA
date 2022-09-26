class Solution {
public:
    // STEP 1: RECURSIVE: TC:O(2^N) SC:O(2^N)
    /*int rob(vector<int>& nums) {
        return helper(nums,nums.size()-1);
    }
    int helper(vector<int> &nums, int i){
        if(i<0)
            return 0;
        return max(helper(nums,i-2)+nums[i], helper(nums,i-1));
    }*/
    // STEP 2: RECURSION WITH TOP-DOWN DP
    // TC: O(N) SC:O(N)
    /*int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return helper(nums,nums.size()-1,dp);
    }
    int helper(vector<int> &nums, int i, vector<int> &dp){
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = max(helper(nums,i-2,dp)+nums[i], helper(nums,i-1,dp));
    }
    */
    // STEP 3: DP BOTTOM-UP
    // TC:O(N) SC:O(N)
    /*int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        dp[0] = 0;          // since no element therefore 0
        dp[1] = nums[0];    // when we consider 1 element than that will be the greatest
        for(int i = 1 ; i<nums.size() ; i++){
            int curr = nums[i];
            dp[i+1] = max(dp[i],dp[i-1]+curr);  // greater between the previous greater or curr val and previous of previous greater
        }
        return dp[nums.size()];
    }*/
    // STEP 4: DP with 2 variables
    // TC:O(N) SC:O(1)
    int rob(vector<int>& nums) {    
        if(nums.size()==0)  return 0;
        int prev2 = 0, prev1 =0;            // sequence is prev2 , prev1 , num
        for(int num:nums){                  // like as of fibonacci series here prev2 will become prev1 
            int temp = prev1;
            prev1 = max(prev2+num,prev1);
            prev2 = temp;
        }
        return prev1;
    }
};