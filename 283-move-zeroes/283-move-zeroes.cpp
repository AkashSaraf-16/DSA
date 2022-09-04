class Solution {
public:
    // two pointer :  we will move j only when we encounter a non zero on i pointer so and when we encounter such situation we will store value at i on j index at last we fill all index after j with 0
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        while(j < nums.size()){
            nums[j] = 0 ;
            j++;
        }
    }
};