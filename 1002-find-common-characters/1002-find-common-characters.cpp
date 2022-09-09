class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
    vector<int> count(26,INT_MAX);
    vector<string> res;
    for(auto s: words){
        vector<int> count1(26,0);
        for(auto c:s){
            count1[c-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            count[i] = min(count[i] , count1[i]);
        }
    }
    for(int i = 0 ; i < 26 ; i++){
        for(int j = 0 ; j<count[i] ; j++){
            res.push_back(string(1,i+'a'));
        }
    }
        return res;
    }
};