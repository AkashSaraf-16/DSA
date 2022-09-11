class Solution {
public:
    // T.C: O(NlogK) S.C: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //min priority queue
        for(auto num:nums){
            mp[num]++;
        }
        
        for(auto e : mp){
            pq.push({e.second,e.first});
            if(pq.size()>k)  // only maintaining k items at a time hence T.C:O(NlogK)
                pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};