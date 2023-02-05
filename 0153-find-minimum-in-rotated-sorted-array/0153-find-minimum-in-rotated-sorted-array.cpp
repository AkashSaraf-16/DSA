class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),s=0,e=nums.size()-1;
        if(nums[s]<=nums[e])
            return nums[s];
        while(s<=e){
            int m=(e-s)/2+s;
            int prev=(m-1+n)%n;
            int next=(m+1)%n;
            if(nums[m]<nums[prev])
                return nums[m];
            else if(nums[next]<nums[m])
                return nums[next];
            // Think these 2 conditions as when we are on sorted part we will minimize e to reach min
            // normal BS logic
            else if(nums[m]<nums[e])
                e=m-1;
            else
                s=m+1;
        }
        return INT_MAX;
    }
};