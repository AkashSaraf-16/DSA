class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        /* BRUTE FORCE:
        vector<int> ans(nums.size());
        int k = 0 , l= 1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(!(nums[i]%2)) {           // even
                ans[k] = nums[i];
                k+=2;
            }
            else{                       //  odd
                ans[l] = nums[i];
                l+=2;
            }
        }
        return ans;*/
        int n = nums.size();
        int i = 0 , j = n-1;
        while(i<n){
            // we will find the even index where we have odd number
            while(i<n && nums[i]%2== 0)
                i+=2;
            // if we reach n then we have already our ans array
            if(i==n)
                break;
            // we will find an odd index where we have even number
            while(j>=0 && nums[j]%2== 1)
                j-=2;
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};