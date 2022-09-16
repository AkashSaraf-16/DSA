class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128,0);
        for(char c:s)
            cnt[c]++;
        
        int ans=0;
        for(auto c:cnt){
            ans+=c/2*2;
            if(ans%2==0 && c%2==1)
                ans++;
        }
        return ans;
    }
};