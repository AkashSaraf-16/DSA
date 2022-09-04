class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size()<ransomNote.size())
            return false;
        vector<int> mp(26,0);
        for(int i= 0 ; i<ransomNote.size() ; i++)
            mp[ransomNote[i]-97]++;
        for(int i= 0 ; i<magazine.size() ; i++)
            mp[magazine[i]-97]--;
        for(int i = 0 ; i <26 ; i++){
            if(mp[i]>0)
                return false;
        }
        return true;
    }
};