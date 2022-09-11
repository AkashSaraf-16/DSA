// T.C : O(NlogK) S.C: O(N)
#define pis pair<int,string>        // pair of string and integer
class mycomprator{
  public:
    bool operator()(const pis &p1 , const pis &p2){ // a comprator function based on set of rules given in question
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pis,vector<pis>,mycomprator> pq; // not min or max heap custom heap
        unordered_map<string,int> freq;
        
        for(auto word : words)
            freq[word]++;
        
        for(auto m : freq){
            pq.push({m.second,m.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string> res(k);
        int i = k-1;
        
        while(!pq.empty()){
            res[i--] = pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};