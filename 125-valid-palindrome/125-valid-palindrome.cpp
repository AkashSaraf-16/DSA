class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto ch:s){
            if(ch!=' ' && isalpha(ch) || isdigit(ch)){
                temp+= tolower(ch);                
            }
        }
        cout<<temp;
        int i=0,n=temp.length()-1;
        for(int i=0 ; i<=n ;i++){
            if(temp[i]!=temp[n-i])
                return false;
        }
        return true;
    }
};