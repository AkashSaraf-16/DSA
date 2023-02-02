class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int m=num1.length(),n=num2.length();
        vector<int> mul(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                mul[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                mul[i+j]+=mul[i+j+1]/10;
                mul[i+j+1]%=10;
            }
        }
        int i=0;
        string res="";
        while(mul[i]==0)
            i++;
        while(i<m+n)
            res+=to_string(mul[i++]);
        return res;
    }
};