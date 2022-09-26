class Solution {
public:
    /*  BOTTOM-UP DP
    int longestPalindromeSubseq(string s) {
        int m = s.length(), n = s.length();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        string t = s;
        reverse(s.begin(),s.end());
        return helper(s,t,m,n,dp);          // here we are finding the longest common subsequence between s and reverse of s
    }
    int helper(string a,string b,int m ,int n, vector<vector<int>> dp){
        if(m==0 || n==0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(a[m-1] == b[n-1])
            return dp[m][n] = 1+helper(a,b,m-1,n-1,dp);
        else
            return dp[m][n] = max(helper(a,b,m-1,n,dp),helper(a,b,m,n-1,dp));
    }
    */
    // TOP DOWN DP
    // TC:O(N*N) SC:O(N*N)
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        string t =s;
        reverse(s.begin(),s.end());
        for(int i=0 ; i<=n ; i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(s[i-1] == t[j-1])            // if characters are equal 
                    dp[i][j] = 1+dp[i-1][j-1];
                else                        // if they arent equal
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    
};   