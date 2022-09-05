class Solution {
public:
    void generatePermutation(int ind , vector<vector<int>> &ans , vector<int> &nums ){
        //TC: O(N!*N) SC:O(N!)
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ;i<nums.size();i++){
            swap(nums[ind] ,nums[i]);
            generatePermutation(ind+1,ans,nums);
            swap(nums[ind] ,nums[i]);      //backtrack
        }
       /* for(int i = 0 ; i < nums.size() ; i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                generatePermutation(ds,ans,nums,freq);
                ds.pop_back();
                freq[i] = 0;
            }
        } */
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
   // vector<int> ds;
   // int freq[nums.size()];
   // for(int i=0;i<nums.size();i++)
   //     freq[i] = 0;
   // generatePermutation(ds,ans,nums,freq);
    generatePermutation(0,ans,nums) ;
    return ans;
    }
};