class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size()-1;
        int n = s.size()-1;
        int i = 0 , j = 0 ;
        int ans = 0;
        while(i<=m){
            while(j<=n){
                if(g[i]-s[j] <= 0){
                    ++ans;
                    s[j] = 0;
                    break;
                }
                ++j;
            }
            i++;
        }
        return ans;
    }
};