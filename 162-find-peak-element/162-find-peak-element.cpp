class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0 , e = nums.size()-1;
        if(e == 0) return s;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(mid>0 && mid<e){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                    return mid;
                else if(nums[mid-1]>nums[mid]){
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            else if(mid == 0){
                if(nums[mid] > nums[mid+1])
                    return mid;
                else
                    s = mid+1;
            }
            else{
                if(nums[mid] > nums[mid-1])
                    return mid;
                else
                    e = mid-1;
            }
        }
        return s;
    }
};