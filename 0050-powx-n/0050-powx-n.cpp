class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
        }
        double pow=1;
        long num=labs(n);
        while(num){
            if(num&1){
                pow*=x;
            }
            x*=x;       // x power will rise by 1 now
            num>>=1;    // moving to next index(think in terms of binary number format)
        }
        return pow;
    }
};