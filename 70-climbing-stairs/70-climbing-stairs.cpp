class Solution {
public:
    int countStairs(int n){
        int arr[n+1];
        arr[0] = arr[1] =1;
        for(int i=2 ; i<=n ; i++){
        arr[i] = arr[i-1] + arr[i-2];    // can reach i by taking 1 step or 2 step
        }
        int ans = arr[n];
        return ans;
    }
    int climbStairs(int n) {
        return countStairs(n);
        // int k =2;
        // int dp[n+1];
        // dp[0] = dp[1] = 1;
        // for(int i = 2 ; i<=n ; i++){
        //     int ans = 0;
        //     for(int jump = 1 ; jump<=k ; jump ++){
        //         if(i-jump>=0){
        //             ans = ans + dp[i-jump];
        //         }
        //     }
        //     dp[i] =  ans;
        // }
        // return dp[n];
    }
};
