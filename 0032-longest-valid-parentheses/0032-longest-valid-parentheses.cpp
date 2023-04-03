class Solution {
public:
//     TC:O(N)
//     SC:O(N)
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int i=0,maxLen=0;
        while(i<s.length()){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    maxLen=max(maxLen,i-st.top());
            }
            i++;
        }
        return maxLen;
    }
};