class Solution {
public:
    char findTheDifference(string s, string t) {
       /*
        if(s.size() == 0)
            return t[0];
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i = 0 ;
        for(auto it : t){
            if(it != s[i])
                return it;
            ++i;
        }
        return s[0]; 
        */
        char c = 0;
        for(auto cs : s)    c ^= cs;    //The result of XOR is 1 if the two bits are different. 
        for(auto ct : t)    c ^= ct;
        return c;
    }
};