class Solution {
public:
    // BS on answer
    int countSmallnEqual(vector<int> &n , int m){
        int count = 0;
        for(int a: n)
            if(a<=m)
                count++;
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int l = 1 , h = nums.size();
        int res;
        while(l<=h){
            int mid = (l+h)/2;  
            // finding the no. of numbers less than equal to present number
            if(countSmallnEqual(nums,mid)>mid){ // if greater save it n search again
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};