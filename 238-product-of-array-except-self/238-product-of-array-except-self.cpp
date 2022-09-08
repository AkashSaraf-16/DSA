class Solution {
public:
    // Single pass TC:O(N) SC:O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
     /*   vector<int> fromLeft(n,1);
        vector<int> fromRight(n,1);
        
        for(int i = 1 ; i < n ; i++){
            fromLeft[i] = fromLeft[i-1]*nums[i-1];
            fromRight[i] = fromRight[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i = 0 ; i<n ; i++){
            res[i] = fromLeft[i]*fromRight[n-1-i];
        }
        return res;
        */
    // Single pass TC:O(N) SC:O(N)
        int fromLeft = 1, fromRight = 1;
        vector<int> res(n,1);
        for(int i=0; i<n ; i++){
            res[i]*=fromLeft;
            fromLeft*=nums[i];
            res[n-1-i]*=fromRight;
            fromRight*=nums[n-1-i];
        }
        return res;
    }
};