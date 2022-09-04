class Solution {
public:
    int addDigits(int num) {
        /*int ans =0 ;
        while(num>0){
            int digit = num%10;
            ans += digit;
            num /= 10;
            if(ans>9)
                ans = ans-9;
            if(num == 0 && (ans/10)>0){
                num = ans;
                ans = 0;
            }
        }   */
        if(num ==0) return num;
        
        return num%9 == 0 ? 9 : num%9;
    }
};