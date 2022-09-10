class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // fixed size sliding window
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(i<nums.size()){
            // first reaching till kth element 
            if(i-j<=k){
                if(mp.find(nums[i]) != mp.end())
                    return true;
                else
                    mp[nums[i]]++;
            }
            // once we have reached the k th element we will move our left pointer
            else{
                // updating the right pointer
                mp[nums[i]]++;
                // updating the left pointer
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                j++;
                if(mp[nums[i]]>1)
                    return true;
            }
            i++;
        }
        return false;
    }
};