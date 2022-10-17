/*int bin(vector<int>&v,int x,int high,int low){
    int n=v.size();
     // high=n-1,low=0;
     int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(v[mid]==x){
           return mid;
        }
        else if (v[mid]<x){
            low=mid+1;}
        else{
            high=mid-1;
        }


    }
   return -1;
}


int pivt(vector<int>& v){
    int n=v.size();
    int low=0,high=n-1,mid;
    while(low<high){
        mid=low+(high-low)/2;
        if(v[mid]>=v[0]){
            low=mid+1;
        }else{
            high=mid;
        }
 
    }return low;
}

class Solution {
public:
    


int search(vector<int>& nums, int target) {
        int pivot=pivt(nums);
        int n=nums.size();
        if(target>=nums[pivot]&&target<=nums[nums.size()-1]){
            return bin(nums,target,n-1,pivot);
        }
        else{
            return bin(nums,target,pivot-1,0);
        }
    
}

};*/
class Solution {
public:
    int getMinIndex(vector<int>& nums){         // get minimum element index
        int s = 0 , n = nums.size() , e=n-1 ;
        while(s<=e){
            int mid = (e-s)/2 + s;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n; 
            if(nums[mid]>nums[next])
                return next;
            if(nums[mid]<nums[prev])
                return mid;
            if(nums[mid] < nums[e])
                e = mid-1;
            else
                s = mid+1;
        }
        return 0;
    }
    int Bsearch(vector<int> nums , int s , int e , int target){ // binary search
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
                e = mid-1;
            else
                s = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index = getMinIndex(nums);      // first get the minimum elements's index
        if(Bsearch(nums,0,index-1,target) == -1)    // then search in range of 0 - index-1 (since we will have sorted numbers here) and index - size-1(since we will have sorted numbers here)
            return Bsearch(nums,index,nums.size()-1,target);
        return Bsearch(nums,0,index-1,target);
    }
};