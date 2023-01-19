class Solution {
public:
    int mySqrt(int x) {
        long int l=0,h=x,temp;
        while(l<=h){
            long int m=(h-l)/2+l;
            if(m*m==x)
                return m;
            else if(m*m<x){
                temp=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        return temp;
    }
};