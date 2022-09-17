class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        // Adding the intervals which are less and non overlapping with newInterval
        while(i<intervals.size() && (intervals[i][1]<newInterval[0])){
                res.push_back(intervals[i++]);
        }
        // Adding the overlapping intervals
        while(i<intervals.size() && (intervals[i][0]<=newInterval[1])){
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        // adding the union of overlapping intervals
        res.push_back(newInterval);
        // adding the rest intervals greater than overlapping interval
        while(i<intervals.size()){
            res.push_back(intervals[i++]);
        }
        return res;
    }
};