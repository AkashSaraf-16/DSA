class Solution {
public:
//     DP: dp array's ith index represents the max length of valid parenthesis at index i.
    int longestValidParentheses(string s) {
        int maxLen=0;
        vector<int> dp(s.length(),0);
        for(int i=1;i<s.length();i++){
            if(s[i]==')' && s[i-1]=='(')    // expression like  ....()
                dp[i]=(i>=2?dp[i-2]:0)+2;
            else if(i-dp[i-1]>0 && s[i]==')' && s[i-1]==')' && s[i-dp[i-1]-1]=='(')
//          if we have expression like this : )(()) try to pput the values in above expression you will get it.
                dp[i]=dp[i-1]+2+((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0);
//          this last expression dp[i-dp[i-1]-2] can be understood from debugging expr like this : )()(()(()))
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};