class Solution {
public:
    int getFirst(vector<int>& nums , int target ){
        int ans =-1,s=0, e = nums.size()-1;
        while(s<=e){
        int m= s + (e-s)/2;
        if(nums[m] == target){
            ans = m;
            e = m-1;        /// TO GET THE LEFTMOST INDEX
        }
        else if(nums[m] > target)  
            e = m-1;
        else
            s = m+1;
        }
        return ans;
    }
    int getLast(vector<int>& nums , int target ){
        int ans =-1,s=0, e = nums.size()-1,m;
        while(s<=e){
        m= s + (e-s)/2;
        if(nums[m] == target){
            ans = m;
            s = m+1;        /// TO GET THE  RIGHTMOST INDEX
        }
        else if(nums[m] > target)  
            e = m-1;
        else
            s = m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0] = getFirst(nums , target);
        if(ans[0] == -1)
            return ans;
        ans[1] = getLast(nums , target);
        return ans;
        
    }        
};
