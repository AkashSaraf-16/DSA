class Solution {
public:
// TC:O(N) SC:O(N)
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> freq;
        vector<int> res;
        int i=0,j=0,counter,len=INT_MAX;
        // Get the freq of chars of p
        for(auto c:p){
            freq[c]++;
        }
        // Get the size of map to track the condition at a time
        counter=freq.size();
        // Start the loop from left 
        while(i<s.length()){
            // If the char is present in map dec its freq. and if its freq == 0 then decthe counter it shows we have fully found one character
            if(freq.find(s[i])!=freq.end()){
                freq[s[i]]--;
                if(freq[s[i]]==0)
                    counter--;
            }
            // Inc the right pointer(i)
            i++;
            // Till counter == 0 we will inc our left pointer and if found in map we will inc the freq  
            while(counter==0){
                if(freq.find(s[j])!=freq.end()){
                    freq[s[j]]++;
                    if(freq[s[j]]>0)
                        counter++;
                }
                // If the diff b/w ;eft and right pointer is equal to length of string push in ans the left pointer.
                if(i-j==p.length()){
                    res.push_back(j);
                }
                j++;
            }
        }
        return res;
    }
};