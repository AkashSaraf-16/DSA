class Solution {
public:
    bool isPalindrome(int x) {
     /*   string bob = to_string(x);
        for(int i = 0; i<bob.length()/2;i++) {
            if(bob[i]!=bob[bob.length()-1-i]) {
                return false;
            }
        }
        return true; */
        if(x<0){
            return false;
        }
        long int rev = 0,i=0;
        long int temp = x;
        while(x>=1){
            int digit = x%10;
            rev = rev*10 + digit;
            x/= 10;
        }
        if(rev == temp)
            return true;
        return false;
    }
    
};