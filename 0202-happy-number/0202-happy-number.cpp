class Solution {
public:
    int getNext(int n){
        int val=0;
        while(n){
            int digit=n%10;
            val+=digit*digit;
            n/=10;
        }
        return val;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=getNext(slow);
            fast=getNext(getNext(fast));   
        }while(slow!=fast);
        return slow==1;
    }
};