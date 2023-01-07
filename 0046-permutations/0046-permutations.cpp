class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &res, int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        // idx here represents the index whose value we want to fix at present
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(nums,res,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,res,0);
        return res;
    }
};