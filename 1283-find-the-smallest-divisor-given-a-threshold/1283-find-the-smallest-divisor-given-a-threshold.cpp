class Solution {
public:
    // TC: (Nlogh)  SC: O(1)
    int sumAfterDivision(vector<int>& nums, int divisor){
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i]/divisor;
            if(nums[i]%divisor != 0){    // imitating the ceil function
                sum+= 1;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1 , h = *max_element(nums.begin(),nums.end());
        int ans = h;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(sumAfterDivision(nums,mid)<=threshold){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};