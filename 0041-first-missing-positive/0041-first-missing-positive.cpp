class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i];
            if(element>=1 && element<=n){
                int correctPos=element-1;
                if(nums[correctPos]!=element){
                    swap(nums[correctPos],nums[i]);
                    i--; // we have to again check whther now at pos i we have correct number or not
                }   
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])
                return i+1;
        }
        return n+1;
    }
};