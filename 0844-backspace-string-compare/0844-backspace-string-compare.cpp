class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length()-1 , n = t.length()-1;
        while(m >= 0 || n >= 0){
            if(m>=0 && s[m] == '#'){
                int count = 2;
                while(count > 0){
                    --m;
                    count--;
                    if(m>=0 && s[m] == '#')
                        count+= 2;
                };
            }
            if(n>=0 && t[n] == '#'){
                int count = 2;
                while(count > 0){
                    --n;
                    count--;
                    if(n>=0 && t[n] == '#')
                        count+= 2;
                };
            }
            if(m>=0 && n>=0 && s[m] != t[n])
                return false;
            else if(m<0 && n>=0 || m>=0 && n<0)
                return false;
            else{
                m--;
                n--;
            }
                
        }
        return true;
    }
};