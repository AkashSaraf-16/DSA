class Solution {
public:
    int helper(vector<int> &nums,int ind,vector<int> &dp){
        if(ind==nums.size()-1)
            return dp[ind]=2;
        if(dp[ind]!=1)
            return dp[ind];
        if(nums[ind]==0)
            return dp[ind]=0;
        for(int i=1;i<=nums[ind];i++){
            if(helper(nums,ind+i,dp)==2)
                return dp[ind]=2;
            else 
                continue;
        }
        return dp[ind]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        if(nums.size()>1 && nums[0]==0)
            return false;
        return helper(nums,0,dp)==2?true:false;
    }
};