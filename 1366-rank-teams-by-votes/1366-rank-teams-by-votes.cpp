class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].length();
        string res = votes[0];
        vector<vector<int>> freq(26,vector<int>(n));
        // getting th freq at that particular slot 
        for(auto vote : votes){
            for(int i = 0 ; i<n ; i++){
                freq[vote[i]-'A'][i]++;
            }
        }
        
        // sorting it as per our rules
        sort(res.begin() , res.end() , [&](auto &a , auto &b){
            if(freq[a-'A'] == freq[b-'A'])
                return a<b;
            return freq[a-'A'] > freq[b-'A'];
                
        });
        return res;
    }
};