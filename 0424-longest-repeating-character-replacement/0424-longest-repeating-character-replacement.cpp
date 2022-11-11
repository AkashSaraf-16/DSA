class Solution {
public:
    // TC:O(N*26) SC:O(N)
    int characterReplacement(string s, int k) {
        // first think like we have to replace all the distinct characters to make a single longest repeating string. We can do this by replacing all the chars excpet the one whose freq is highest, i.e., length of string- freq of most repeating char. Now we can put the contstraint of k i.e length of string- freq of most repeating char <=k.
        vector<int> freq(26,0);
        int maxCharCount=0,i=0,j=0,res=0,n=s.length();
        while(j<n){
            freq[s[j]-'A']++;
            if(maxCharCount < freq[s[j]-'A']){
                maxCharCount=freq[s[j]-'A'];
            }
            // Checking if we havent consumed k fully
            while(j-i+1-maxCharCount>k){
                freq[s[i]-'A']--;
                i++;
                for(int i=0;i<26;i++){
                    maxCharCount=max(maxCharCount,freq[i]);
                }
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};