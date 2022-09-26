class Solution {
public:
    // TC:O(2^N) SC:O(1) 
    // RECURSIVE:
    /*int numDecodings(string s) {
        return helper(s,0);
    }
    int helper(string &s, int i){
        if(i>=s.size())     // BASE CASE(GREATER THAN EQUAL TO BECOZ WHEN WAY2 WAS CALLED IT MAY RESULT TO ARRAY OUTOF BOUND)
            return 1;
        if(s[i] == '0')     // HANDLING THE 0 CASE
          return 0;
        int way1 = helper(s,i+1);   // WHEN CONSIDERING ONLY ONE CHAE AT A TIME
        int way2 = 0 ;
        if(i<s.size()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0'< 7)))
            // IF THIS COND. SATISFIES WE CAN CONSIDER 2 CHARS ALSO
            way2 = helper(s,i+2);
        return way1+way2;
    }*/
    // TC:O(N) SC:O(N)
    // BOTTOM UP DP - MEMOIZED
    /*int numDecodings(string s) {
        vector<int> mem(s.size()+1,-1);
        mem[s.size()] = 1; // there is always 1 way if reach till n
        return helper(s,0,mem);
    }
    int helper(string &s , int i , vector<int> &mem){
        if(i>=s.size())
            return 1;
        if(mem[i]!=-1)
            return mem[i];
        if(s[i] == '0')
            return mem[i] = 0;
        int way1 = helper(s,i+1,mem);
        int way2 = 0;
        if(i<s.size()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0'< 7)))
            // IF THIS COND. SATISFIES WE CAN CONSIDER 2 CHARS ALSO
            way2 = helper(s,i+2,mem);
        return mem[i] = way1+way2;
    }*/
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        dp[n] = 1;      // there is always 1 way to decode if we reach till the end 
        // we will start from end(right side of input becoz no. of ways depend on the right part)
        for(int i = n-1 ; i>=0 ; i--){
            if(s[i] == '0')
                dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0'< 7)))
                    dp[i]+=dp[i+2];
                
            }
            
        }
        return s.empty() ? 0:dp[0];  // dp[0] becoz it will contain no. of ways to decode the string 's' starting from index 0(whole string 's')
    }
};