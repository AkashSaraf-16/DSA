class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int last=INT_MIN,nonOverLapping=0;
        for(int i=0;i<intervals.size();i++){
            // If this interval is non-overlapping
            if(intervals[i][0]>=last){
                last=intervals[i][1];
                nonOverLapping++;
            }
            else
                last=min(last,intervals[i][1]);
        }
        // minimum overalapping interval = tottal-non overalapping
        return intervals.size()-nonOverLapping;
    }
};