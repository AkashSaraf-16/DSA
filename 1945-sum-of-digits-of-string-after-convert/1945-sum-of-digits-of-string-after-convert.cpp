class Solution {
public:
    int getVal(int val){
        int sum = 0;
        if(val>=0 && val<=9)
            return val;
        else{
            while(val){
                int digit = val%10;
                sum += digit;
                val /= 10;
            }
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int sum = 0 , val;
        for(auto it : s){
            val = it - 'a' + 1;
            sum += getVal(val);
        }
        --k;
        while(k>0){
            sum = getVal(sum);
            --k;
        }
        return sum;
    }
};