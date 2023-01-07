class Solution {
public:
    void helper(vector<int> &nums,vector<int> ds,vector<vector<int>> &res,int idx){
        if(idx==nums.size()){
            res.push_back(ds);
            return;
        }
        // pick
        ds.push_back(nums[idx]);
        helper(nums,ds,res,idx+1);
        // not pick
        ds.pop_back();
        helper(nums,ds,res,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(nums,ds,res,0);
        return res;
    }
};