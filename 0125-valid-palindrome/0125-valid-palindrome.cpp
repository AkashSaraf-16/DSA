class Solution {
public:
    bool isPalindrome(string s) {
        string m;
        for(auto c:s){
            if(isalpha(c)||isdigit(c)){
                if(isalpha(c))
                    c=tolower(c);
                m+=c;
            }
            if(c==' ')
                continue;
        }
        cout<<m;
        string t=m;
        reverse(m.begin(),m.end());
        return t==m;
        
    }
};