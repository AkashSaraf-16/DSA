class Solution {
public:
    vector<vector<int>> dp;
    bool targetSum(vector<int> &nums,int target,int ind,vector<vector<int>> &dp){
        if(ind==nums.size()){
            if(target==0)
                return true;
            else 
                return false;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int pick=false,notPick=false;
        if(nums[ind]<=target){
            pick=targetSum(nums,target-nums[ind],ind+1,dp);
        }
        notPick=targetSum(nums,target,ind+1,dp);
        return dp[ind][target] = pick | notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
            sum+=num;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        
        return sum%2 ? false:targetSum(nums,sum/2,0,dp);
    }
};