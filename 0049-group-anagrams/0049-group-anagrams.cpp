class Solution {
public:
// TC:O(NM) N:No. of words M:No. of chars in longest word SC:O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str:strs){
            vector<int> freq(26,0);
            // Getting the frequency distribution per character in a particular word
            for(char c:str)     freq[c-'a']++;
            string key="";
            for(int i:freq)
                key+=i;
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto m:mp){
            res.push_back(m.second);
        }
        return res;
    }
};