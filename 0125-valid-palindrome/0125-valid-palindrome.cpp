class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(char c:s){
            if(c!=' ' && (isalpha(c) || isdigit(c)))
                t+=tolower(c);
        }
        cout<<t;
        string temp=t;
        reverse(t.begin(),t.end());
        return t==temp;
    }
};