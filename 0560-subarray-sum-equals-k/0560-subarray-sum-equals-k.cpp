class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,res=0;
        for(int num:nums){
            sum+=num;
            if(sum==k){
                res++;
            }
            if(mp.find(sum-k)!=mp.end()){
                res+=mp[sum-k];
            }
            if(mp[sum]){
                mp[sum]++;
            }
            else
                mp[sum]=1;
        }
        return res;
    }
};