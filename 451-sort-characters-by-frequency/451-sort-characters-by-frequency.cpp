class Solution {
public:
    // T.C: O(NlogN) S.C: O(N)
    string frequencySort(string s) {
        vector<int> mp(128,0);
        priority_queue<pair<int,char>> pq;
        
        for(auto c : s){
            mp[c]++;
        }
        
        for(int i = 0 ; i < 128 ; i++){
            if(mp[i]>0){
                pq.push({mp[i],i});
            }
        }
        
        string res="";
        
        while(!pq.empty()){
            int x = pq.top().first;
            char c = pq.top().second;
            for(int i = 1 ; i<= x ; i++)
                res+= c;
            pq.pop();
        }
        
        return res;
        
    }
};