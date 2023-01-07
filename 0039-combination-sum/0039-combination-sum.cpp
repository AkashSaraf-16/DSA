class Solution {
public:
    void helper(vector<int> &candidates,vector<vector<int>> &r,vector<int> &ds, int target, int idx){
        if(target==0){
            r.push_back(ds);
            return;
        }
        // checking for each index in candidates whether we can take it or not 
        while(idx<candidates.size() && target-candidates[idx]>=0){
            ds.push_back(candidates[idx]);
            helper(candidates,r,ds,target-candidates[idx],idx);
            idx++;
         // backtracking
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> r;
        vector<int> ds;
        helper(candidates,r,ds,target,0);
        return r;
    }
};