class Solution {
public:
    void helper(vector<int> nums,vector<vector<int>> &res, int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[idx]){
                swap(nums[i],nums[idx]);
                helper(nums,res,idx+1);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,res,0);
        return res;
    }
};