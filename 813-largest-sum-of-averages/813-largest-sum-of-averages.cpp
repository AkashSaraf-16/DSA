class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(),vector<double>(k+1,-1));
        return helper(nums,0,k,dp);
    }
    double avg(vector<int> &n , int prev , int ind){
        double a = 0.000000;
        for(int i = prev ; i<= ind ;i++){
            a += n[i];
        }
        a = a/(ind-prev+1);
        return a;
    }
    double helper(vector<int> &n , int ind , int k , vector<vector<double>> &dp){
        if(ind>= n.size())
            return 0;
        if(k == 1){
            return dp[ind][1] = avg(n,ind,n.size()-1);
        }
        if(dp[ind][k] != -1)
            return dp[ind][k];
        double ans = 0.000000, sum = 0.000000;
        for(int i = ind ; i < n.size() ; i++){
            sum+= n[i];
            ans = max(ans,sum/(i-ind+1)+helper(n,i+1,k-1,dp));  // here we are calculating the avg of no. from ind till i and then recursively calling for the next indexe with reduced k
        }
        return dp[ind][k]= ans;
    }
};