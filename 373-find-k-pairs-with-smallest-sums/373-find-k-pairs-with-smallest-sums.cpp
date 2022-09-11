#define pip pair<int,pair<int,int>>
class Solution {
public:
    //T.C:O(KLogM) S.C:O(N)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        vector<vector<int>> res;
        int m = nums1.size() , n = nums2.size();
        if(m == 0 || n == 0 ) return res;
        for(int i = 0 ; i < m ; i++){
            int sum = nums1[i] + nums2[0];
            pq.push({sum,{i,0}});       // we are storing index because later on we will need index to traverse        
        }
        
        while(!pq.empty() && k-- >0){   // we are doing k-- here becoz when we push new piars they are going to greater than older ones so no need to push all possible pairs and then get k smallest of them
            int i = pq.top().second.first , j = pq.top().second.second;
            pq.pop();
            
            vector<int> v = {nums1[i],nums2[j]};
            res.push_back(v);
            if(j+1 == n)    continue;   // if we reach the end of list 2(edge case)
            pq.push({nums1[i]+nums2[j+1],{i,j+1}}); // here is why we are using index
        }
        
        return res;
    }
};