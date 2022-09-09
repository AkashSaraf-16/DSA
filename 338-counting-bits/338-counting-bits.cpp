class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n+1);   
        t[0] = 0; 
        for(int i = 1 ; i < n+1 ; i++){
            t[i] = (i&1) + t[i/2];
        }
        return t;
    }
};