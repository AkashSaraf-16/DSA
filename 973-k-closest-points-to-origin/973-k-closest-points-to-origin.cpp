class Solution {
public:
    //  T.C:O(NlogK)
    int pythagores(int abscissa , int ordinate){
        return pow(abscissa,2)+pow(ordinate,2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = pythagores(x,y);
            pq.push({dist,{x,y}});
            if(pq.size()>k)
                pq.pop();
        }
        
        
        vector<vector<int>> res;
        while(!pq.empty()){
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            res.push_back(temp);
            pq.pop();
        }
        return res;
    }
};