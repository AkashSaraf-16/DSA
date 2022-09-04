//help in easy switch to follow up case
#define CHAR_COUNT 26
#define FIRST_CHAR 97   //ASCII code of first char('a' in this case)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        int freqArray[CHAR_COUNT] = {0};
		
        for(int i = 0; i < s.length(); i++){
            ++freqArray[s[i] - FIRST_CHAR];
            --freqArray[t[i] - FIRST_CHAR];
        }

        for(int i = 0; i < CHAR_COUNT; i++)
            if(freqArray[i]!=0) return false;
        return true;
    }
};