class Solution {
public:
	int ans = 0;
	int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(),vector<int>(B.size(),-1));
		solve(A, B, 0, 0,dp);
		return ans;
	}
	int solve(vector<int>& A, vector<int>& B, int i, int j , vector<vector<int>> &dp) {
		if(i >= size(A) || j >= size(B)) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
		int common = A[i] == B[j] ? 1 + solve(A, B, i+1, j+1,dp) : 0;  // longest common subarray starting at A[i] & B[j]
		ans = max(ans, common);                                     // update ans to hold max length found till now
		solve(A, B, i+1, j,dp), solve(A, B, i, j+1,dp);                   // recurse to solve for each possible (i, j)
		return dp[i][j] = common;
	}
};	