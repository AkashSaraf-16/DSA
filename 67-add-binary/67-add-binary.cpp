class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1 , n = b.length()-1;
        string ans = "";
        int sum = 0,carry = 0,x,y;
        while(m>=0 || n>=0){
            x = m>=0 ? a[m]-'0' : 0;
            y = n>=0 ? b[n]-'0' : 0;
            sum = x+y+carry;
            ans+= to_string(sum%2);
            carry = sum/2;
            m--;
            n--;
        }
        if(carry)
            ans+= '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};