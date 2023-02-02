class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xoR = 0,n = nums.size();
        for(int i = 0;i<n;i++) {
            xoR ^= nums[i];
        }
        
        int mask = 1;
        while((mask & xoR) == 0) {         // tryig to find the rightmost set bit
                mask = mask << 1;           // if not found shifting the bits 1 by left
        }
        
        
        int a = 0, b = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i] & mask) a ^= nums[i];
            else b ^= nums[i];
        }
        return {a, b}; 
    }
};