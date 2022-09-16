class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){       // remove the least significant bit '1'
            n = n&(n-1);
            ans++;
        }
        return ans;
    }
};