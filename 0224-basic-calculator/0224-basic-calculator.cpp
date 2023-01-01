class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;         // (state of sum,sign)
        long long int sum=0;
        int sign=+1;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(isdigit(c)){
                long long int num=0;
                // get the full number if its multiple digit
                while(i<s.length() && isdigit(s[i])){
                    num=num*10+s[i]-'0';
                    i++;
                }
                // to avoid skipping sign of next number
                --i;
                sum+=(num*sign);
                sign=+1;
                
            }
            else if(c=='('){
                // save the state
                st.push({sum,sign});
                // reseting the sum and sign
                sum=0;
                sign=+1;
            }
            else if(c==')'){
                // Accumulate the sum 
                sum=st.top().first+(st.top().second*sum);
                st.pop();
            }
            else if(c=='-'){
                sign=(-1*sign);
            }
        }
        return sum;
    }
};