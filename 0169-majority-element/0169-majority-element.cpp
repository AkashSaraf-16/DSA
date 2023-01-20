class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,maj;
        for(int num:nums){
            if(count==0){
                maj=num;
            }
            count+= maj==num?1:-1;
        }
        return maj;
    }
};