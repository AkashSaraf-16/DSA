class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> ds, int index){
        ans.push_back(ds);
        for(int i = index ; i < nums.size() ; i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(nums,ans,ds,i+1);
            ds.pop_back();
        }
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(nums,ans,ds,0);
        return ans;
    }
};