class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int cnt=1,prevEle=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prevEle){
                cnt++;
                prevEle=nums[i];
            }
            if(cnt==3){
                return nums[i];
            }
        }
        return nums[0];
    }
};