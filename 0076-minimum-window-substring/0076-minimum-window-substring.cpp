class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        unordered_map<char,int> win;
        for(auto c : t){
            win[c]++;
        }
        int j = 0 , i = 0 , count = t.size() , len = INT_MAX , start=0;
        while(j<s.length()){
            // calculation
            if(win.find(s[j]) != win.end()){
                if(win[s[j]]>0)
                    count--;    
                --win[s[j]];
            } 
            while(count == 0){
                if(j-i+1 < len)         // we need to store the len and start before shortening the length
                {
                    len = j-i+1;
                    start = i;
                }
                if(win.find(s[i]) != win.end()){
                    ++win[s[i]];                // inc the freq as we are excl. i th index
                    if(win[s[i]]<=0 and j-i+1 < len){   // if after excluding left pointer then also we have all the chars in window 
                        len = j-i+1;
                        start = i;
                    }
                    else if(win[s[i]]>0){       // if we need win[s[i]] after excluding then count+++
                        count++;
                    }
                }
                i++;
            }
            j++; 
        }
        return len<INT_MAX ? s.substr(start , len):"";
    }
};