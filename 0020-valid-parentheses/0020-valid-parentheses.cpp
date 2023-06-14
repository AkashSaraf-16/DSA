class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else if(!st.empty()){
                if(isComplementery(st.top(),c))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        return st.empty();
    }
    bool isComplementery(char a,char b){
        if(a=='(' && b==')')
            return true;
        else if(a=='{' && b=='}')
            return true;
        else if(a=='[' && b==']')
            return true;
        return false; 
    }
};