class Solution {
public:
    // TC:O(LOGN) IN AVG AND O(N) IN WORST CASE
    int findMin(vector<int>& n) {
        int s=0,l=n.size();
        int e =l-1;
        while(s<e){
            int m = s+(e-s)/2;
            if(n[m] > n[e]) s=m+1;          // right part is unsorted hence we can find min here
            else if(n[s] > n[m]) e=m;       // left part is unsorted hence we can find min here
            else e--;                       // mid value equal to end value move towards start
        }
        return n[s];
    }
};