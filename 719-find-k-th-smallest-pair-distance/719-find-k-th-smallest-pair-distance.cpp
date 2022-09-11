class Solution {
public:
    int noOfPairs(vector<int> &nums , int &target){
        int j=0 , count = 0;
        for(int i = 1 ; i<nums.size() ; i++){
            while(nums[i]-nums[j]>target)
                j++;
            count+=i-j;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // setup for binary search on answers
        int low =0 ,high;
        sort(nums.begin(),nums.end());
        high = nums[nums.size()-1]-nums[0];
        for(int i = 0 ; i < nums.size()-1;i++)
            low = min(low,nums[i+1]-nums[i]);
        while(low<high){
            int mid = (low+high)/2;
            if(noOfPairs(nums,mid)<k)
                low = mid+1;
            else 
                high = mid;
        }
        return low;
        
    }
};