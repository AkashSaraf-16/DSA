class Solution {
public:
    // TC : O(maxK.N) SC:O(N)
    string decodeString(string s) {
        int index= 0;
        return decodeHelper(s,index);
    }
    string decodeHelper(string &s , int &index){
        string result;
        // BASE CONDITION
        while(index<s.length() && s[index]!=']'){
            if(!isdigit(s[index])){
                result+=s[index++];
            }
            else{
                int k = 0 ;
                // building the number
                while(index<s.length() && isdigit(s[index]))
                    k = k*10+(s[index++]-'0');
                //once we encounter [ we will start oue next recursion call
                index++;
                string decoded = decodeHelper(s,index);
                // once we get here we will be on ] so ignoring it
                index++;
                for(int i = 1 ; i<= k ; i++){
                    result = result+decoded;
                }
                
            }
        }
        return result;
    }
};