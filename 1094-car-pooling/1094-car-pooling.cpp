class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        int currCap = 0;
        for(auto trip:trips){   // mapping each pick n drop point with the no. of passenger adding/subtracting
            int src = trip[1];
            int dest = trip[2];
            int ppl = trip[0];
            mp[src] += ppl; // this is imp as there may be instances of same pick n drop loaction so we cumulative value
            mp[dest] -= ppl;
        }
        // if it any moment we have currCap > capacity it means trip isnt possible
        for(auto it=mp.begin() ; it!=mp.end() ; it++){
            currCap += it->second;
            if(currCap>capacity)
                return false;
        }
        return true;
    }
};