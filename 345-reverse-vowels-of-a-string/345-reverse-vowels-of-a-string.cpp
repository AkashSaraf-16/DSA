class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch =='i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u'|| ch =='U')
            return true;
        else
            return false;
        
    }
    string reverseVowels(string s) {
        int n = s.length() ;
        int i = 0;
        int j = n-1; 
        while(i < j ){
            if(isVowel(s[i])) {
                if(isVowel(s[j])){
                    swap(s[i] , s[j]);
                    ++i;
                    --j;
                }
                else
                    --j;
            }
            else
                ++i;
        }
    return s;
    }
};