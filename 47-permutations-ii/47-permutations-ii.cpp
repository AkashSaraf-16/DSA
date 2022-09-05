class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms;
        permute(0,perms,nums);
        return perms;
    }
private:

    void permute(int ind , vector<vector<int>> &ans , vector<int> nums ){
        //TC: O(N!*N) SC:O(N!)
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ;i<nums.size();i++){
            if(i == ind || nums[i]!=nums[ind]){
                swap(nums[ind] ,nums[i]);
                permute(ind+1,ans,nums);
            }
        }
    }
};
