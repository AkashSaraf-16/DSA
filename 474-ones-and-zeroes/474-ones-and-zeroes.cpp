class Solution {
public:
    int dp[605][105][105];  // NOTE: here we are using 3d Matrix because 3 variables are changing here
    int count(string s){
        int cnt = 0;
        for(int i = 0 ; i <s.size() ; i++)
            if(s[i] == '0')
            cnt++;
        return cnt;
    }
    int solve(vector<string>& strs, int m, int n ,int i){
        if(i == strs.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        
        int cnt0 = count(strs[i]);
        int cnt1 = strs[i].size() - cnt0;
        int choice1 = INT_MIN;
        if(cnt0 <= m && cnt1 <=n)
            choice1 = solve(strs,m-cnt0,n-cnt1,i+1)+1;
        int choice2 = solve(strs,m,n,i+1);
        dp[i][m][n] = max(choice1,choice2);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};