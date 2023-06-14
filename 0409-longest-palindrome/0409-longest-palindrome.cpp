class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int len=0;
        for(char c:s){
            map[c]++;
        }
        for(auto e:map){
            len+=e.second/2*2;
            if(e.second%2 && len%2==0)
                len++;
        }
        return len;
    }
};