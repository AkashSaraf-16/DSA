class Solution {
public:
    int mySqrt(int x) {
        int sqrt = 0;
        int s = 0 , e = x;
        while(s <= e){
            long long int mid = s + (e-s)/2;
            if(mid*mid<=x){
                sqrt = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return sqrt;
    }
};