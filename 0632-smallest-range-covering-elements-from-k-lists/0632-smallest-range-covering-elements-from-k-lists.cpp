class Solution {
public:
    // TC:O(nklogk) where n:list with max elements
    // SC:O(k)
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int k=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<k;i++){
            // Pushing the first element of all the arrays with the info of which array and what index
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            maxi=max(maxi,nums[i][0]);
        }
        mini=pq.top().first;
        int left=-1e5,right=1e5;
        if(maxi-mini<right-left){
            left=mini;
            right=maxi;
        }
        int curr_list=pq.top().second.first;
        int curr_index=pq.top().second.second;
        pq.pop();
        while(curr_index+1<nums[curr_list].size()){
            pq.push(make_pair(nums[curr_list][curr_index+1],make_pair(curr_list,curr_index+1)));
            maxi=max(maxi,nums[curr_list][curr_index+1]);
            mini=pq.top().first;
            if(maxi-mini<right-left){
                left=mini;
                right=maxi;
            }
            curr_list=pq.top().second.first;
            curr_index=pq.top().second.second;
            pq.pop();
        }
        return {left,right};        
    }
};