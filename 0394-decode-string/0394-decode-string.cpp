class Solution {
public:
    // TC : O(maxK*n) K = numeric value , n = length of string SC : O(n+m)
    string decodeString(string s) {
        stack<string> chars_stck;
        stack<int> freq;
        string currentString;       // string build so far in []
        int k = 0;                  // current number formed before [
        for(char ch : s){
            if(isdigit(ch)){
                k = k*10+(ch-'0');
            }
            else if(ch == '['){
                // pushing the number created so far in stack only when we encounter [ 
                freq.push(k);
                //pushing the char formed so far 
                chars_stck.push(currentString);
                // reset the value of k and currentString so that we can use it in next numeric case
                k = 0;
                currentString = "";
                
            }
            else if(ch == ']'){
                // getting the top string just before the this [] Eg : 3[a2[bc]] here top will be  a as we will need as it is with the other string be repeated
                string decoded = chars_stck.top();
                chars_stck.pop();
                for(int times = 1 ; times<=freq.top() ; times++){
                    decoded = decoded+currentString;
                }
                // processed number hence removing
                freq.pop();
                currentString = decoded;
            }
            else{
                currentString += ch;
            }
        }
        return currentString;
    }
};