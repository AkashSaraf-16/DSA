class Solution {
public:
    // TC:O(N) SC:O(N)
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i] == 0 ? -1:1;
            if(mp.find(sum)!=mp.end()){
                if(res<i-mp[sum])
                    res=i-mp[sum];
            }
            else
                mp[sum]=i;
        }
        return res;
    }
};