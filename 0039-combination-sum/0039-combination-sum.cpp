class Solution {
public:
    void helper(vector<int> candidates,vector<vector<int>> &res,vector<int> &ds,int target, int sum, int idx){
        // Base condition
        if(idx==candidates.size()){
            if(sum==target)
                res.push_back(ds);
            return;
        }
        // pick
        if(candidates[idx]+sum<=target){
            ds.push_back(candidates[idx]);
            helper(candidates,res,ds,target,sum+candidates[idx],idx);
            ds.pop_back();
        }
        // not pick
        helper(candidates,res,ds,target,sum,idx+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(candidates,res,ds,target,0,0);
        return res;
    }
};