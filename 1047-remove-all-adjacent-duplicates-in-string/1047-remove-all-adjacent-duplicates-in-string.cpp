class Solution {
public:
    string removeDuplicates(string s) {
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            s[j]=s[i];
            if(j>0 && s[j]==s[j-1])
                j=j-2;
            j++;
        }
        return s.substr(0,j);
    }
};