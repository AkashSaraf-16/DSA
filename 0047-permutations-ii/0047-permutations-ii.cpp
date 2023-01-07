class Solution {
public:
    void helper(vector<int> nums,vector<vector<int>> &res,int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=idx;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[i],nums[idx]);
            helper(nums,res,idx+1);
            swap(nums[i],nums[idx]);          
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(nums,res,0);
        return res;
    }
};