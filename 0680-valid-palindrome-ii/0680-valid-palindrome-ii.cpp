class Solution {
public:
    int skip = 0;
    bool checkPalindrome(string s, int start , int end){
        while(start<end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        skip++;
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){      // incase of mismatch check both options i.e excluding i and j
                if(skip>1)
                    return false;
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);  
            }
            i++;
            j--;
        }
        return true;
    }
};