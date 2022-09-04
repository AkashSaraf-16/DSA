class Solution {
public:
    /*
    void helper(vector<int> candidates, int target , int sum , vector<vector<int>> &res , vector<int> ds , int index){
        // BASE CASE
            if(index == candidates.size()){
                if(sum == target){
                    res.push_back(ds);
                    ds.clear();
                }
                return;
                
            }
        
        // HYPOTHESIS N INDUCTION
            if(sum+candidates[index]<=target){
                sum+=candidates[index];
                ds.push_back(candidates[index]);
                helper(candidates,target,sum,res,ds,index);
                ds.pop_back();          // backtracking
                sum-=candidates[index]; // backtracking
            }
            helper(candidates,target,sum,res,ds,index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(candidates,target,0,res,ds,0);
        return res;
    }
    */
    void comb(vector<int>& t ,vector<vector<int>>& ans , vector<int>& candidates , int target ,int i ){
        if(target == 0){
            ans.push_back(t) ; 
            return ; 
        }
        while(i < candidates.size() && target - candidates[i] >= 0){
            t.push_back(candidates[i]) ;
            comb(t , ans , candidates , target - candidates[i] , i ) ; 
                i++ ; 
            t.pop_back() ; 
        } 
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {   
        sort(candidates.begin() , candidates.end()) ; 
        candidates.erase(unique(candidates.begin() , candidates.end()) ,candidates.end()) ; 
        vector<int> t ; 
        vector<vector<int>> ans ; 
        comb(t , ans , candidates , target , 0 ) ; 
        return ans ; 
    }
};