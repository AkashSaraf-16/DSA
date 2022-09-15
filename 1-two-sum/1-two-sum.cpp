class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;        // element and index
        int temp;
        for(int i = 0 ; i< nums.size() ; i++){
            temp = target - nums[i];        // finding compliment
            if(mp.count(temp)){
                return vector<int>{mp[temp] , i};   // returning the value of index and current index
            }
            mp.insert({nums[i] , i});
        }
        return vector<int>{};
    }
};