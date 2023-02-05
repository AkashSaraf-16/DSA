class Solution {
public:
    int getMinIndex(vector<int> &nums){
        int l=0,n=nums.size();
        int h=n-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            int next=(mid+1)%n;
            int prev=(n+mid-1)%n;
            if(nums[mid]>nums[next])
                return next;
            if(nums[mid]<nums[prev])
                return mid;
            // since we want to find min hence move h to m-1
            if(nums[mid]<nums[h])
                h=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
    int bs(vector<int> &arr,int t,int l,int h){
        int idx=-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(arr[mid]==t)
                return mid;
            else if(arr[mid]>t)
                h=mid-1;
            else
                l=mid+1;
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
        int index=getMinIndex(nums);
        int res=bs(nums,target,0,index-1);
        if(res==-1)
            return bs(nums,target,index,nums.size()-1);
        return res;
    }
};