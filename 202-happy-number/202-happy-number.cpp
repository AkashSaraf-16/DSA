class Solution {
public:
    // TC : O(logN)  SC:O(1)
    int getNext(int n){
        int sum = 0;
        while(n){
            int d = n%10;
            sum+= d*d;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slowrunner = n;                 
        int fastrunner = n;
        do{
            slowrunner = getNext(slowrunner);
            fastrunner = getNext(getNext(fastrunner));
        }while(slowrunner != fastrunner);
        // return slowrunner == 1;
        return fastrunner == 1;
    }
};