class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> ds, int index){
        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }
        helper(nums,ans,ds,index+1);
        ds.push_back(nums[index]);
        helper(nums,ans,ds,index+1);
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(nums,ans,ds,0);
        return ans;
    }
};