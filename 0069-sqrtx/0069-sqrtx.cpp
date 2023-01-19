class Solution {
public:
    int mySqrt(int x) {
        long int s = 0 , e = x,mid,temp;
        while(s<=e){
            mid = (s+e)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                s = mid+1;
                temp = mid; // taking temp to track the nearest lowest value
            }
            else {
                e = mid-1;;
            }
        }
            return temp;
    }
};