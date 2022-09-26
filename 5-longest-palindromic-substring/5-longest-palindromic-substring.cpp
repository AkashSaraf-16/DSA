class Solution {
public:
    // TC:O(N*N) SC:O(N*N)
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        string ans;
        int maxLength = 0;
        for(int diff = 0 ; diff<n ; diff++){        // diff is difference between i and j index
            for(int i = 0,j=i+diff ; j<n ; i++,j++){    // maintaining the diff between the i n j
                // when only one character
                if(i == j){
                    dp[i][j] = 1;
                }
                // when 2 character we just need to check the two chars
                else if(diff == 1){
                    dp[i][j] = s[i] == s[j] ? 2:0;
                }
                // when more than 2 chars
                else{
                    if(s[i] == s[j] && dp[i+1][j-1])
                        dp[i][j] = dp[i+1][j-1]+2;
                }
                // if the dp[i][j] is not 0 then only there is oint of checking the maxLength and updating the ans string
                if(dp[i][j]){
                    if(j-i+1>maxLength){
                    maxLength = j-i+1;
                    ans = s.substr(i,j-i+1);
                    }                
                }
            }
        }
        return ans;
    }
};