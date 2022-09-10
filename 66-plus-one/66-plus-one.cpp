class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;      // we have to add 1 therefore i can be considered as carry
        int sum = 0;
        for(int i = digits.size()-1 ; i >=0 ; i--){
            sum = (digits[i] + carry)%10;
            carry = (digits[i] + carry)/10;
            digits[i] = sum ; 
        }
        if(carry>0){
            digits.insert(digits.begin(), carry);         // we have to insert the carry at the begining 
        }
        return digits;
    }
};