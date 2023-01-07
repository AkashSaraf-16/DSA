class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &res,vector<int> ds,int idx){
        res.push_back(ds);
        for(int i=idx;i<nums.size();i++){
            ds.push_back(nums[i]);
            helper(nums,res,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(nums,res,ds,0);
        return res;
    }
};