class Solution {
public:
    int firstUniqChar(string s) {
    vector<int> countC(256,0);
    for(auto it : s){
        countC[it] ++;
    }
    for(int i = 0 ; i < s.size() ; i++){
        if(countC[s[i]] == 1)
            return i;
    }
        return -1;
    }
};