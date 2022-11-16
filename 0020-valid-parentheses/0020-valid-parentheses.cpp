class Solution {
public:
    bool checkPair(char b,char a){
        if((a == '(' && b ==')') ||(a == '{' && b =='}') || (a == '[' && b ==']'))
            return true;
        return false;
    }
    bool isValid(string s) {
       stack<char> st;
        int i=0;
        while(i<s.length()){
            if(!st.empty() && checkPair(s[i],st.top())){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        return st.empty();
    }
};