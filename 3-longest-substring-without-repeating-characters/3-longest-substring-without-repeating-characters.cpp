class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // variable sized sliding window
        unordered_map<char,int> mp;
        int j = 0 , i = 0 , len = 0 ;
        while(j < s.length()){
            // calculation
            mp[s[j]]++;
            // if all unique char in window
            if(mp.size() == j-i+1){
                len = max(len,j-i+1);
            }
            // if duplicate char in window
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return len;
    }
};