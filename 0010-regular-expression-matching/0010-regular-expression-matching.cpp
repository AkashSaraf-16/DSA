class Solution {
public:
    // we want input string to be fully equal to pattern
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        return helper(0,s,0,p,dp);
    }
    bool helper(int i , string s , int j , string p , vector<vector<int>> &dp){
        if(i>=s.length() && j>=p.length())    // both the strings are exhausted with matching
            return true;
        if(j>=p.length())       // we have exhausted pattern but havent come up with complete match of s
            return false;
        if(i<s.length() && dp[i][j]!= -1)
            return dp[i][j];
        bool matched = (i<s.length() && (s[i] == p[j] || p[j] == '.'));  // first chrs match
        bool notTake = false , take = false ;
        if((j+1)<p.length() && p[j+1] == '*'){        // if we have preceeding *
            notTake = helper(i,s,j+2,p,dp);     // incase we want to consider * as empty character
            take = false;
            if(matched){
                take = helper(i+1,s,j,p,dp);    // incase we want to consider * as character present at s[i+1] 
            }
            return dp[i][j] = take || notTake;
        }
        if(matched){                // if we dont have preceeding *
            return dp[i][j] = helper(i+1,s,j+1,p,dp);
        }
        return dp[i][j] = false;    // if the chars present at the indices are not equal
        
    }
};