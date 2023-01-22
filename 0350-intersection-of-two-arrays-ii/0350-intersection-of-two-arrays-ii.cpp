class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto num:nums1){
            mp[num]++;
        }
        vector<int> res;
        for(auto num:nums2){
            if(mp[num]>0){
                res.push_back(num);
                mp[num]--;
            }
        }
        return res;
    }
};