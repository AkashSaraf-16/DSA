class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lhs(nums.size(),1); // constant space
        
        int next;       // to store the (i+1)th element while calculating the rhs product part
        // calculating lhs array : an array which has product of all elements before that index
        for(int i = 1 ; i < nums.size() ; i++){
            lhs[i] = lhs[i-1]*nums[i-1]; 
        }
        next = nums.back();
        nums.back() = 1;
        // calculating rhs array : an array which has product of all elements after that index
        for(int i = nums.size()-2 ; i>=0 ; i--){
            int temp = nums[i];
            nums[i] = nums[i+1]*next;
            next = temp;
        }
        // nums[i] = lhs[i]*rhs[i](rhs[i] = nums[i] as I have implemented it in the same array)
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] *= lhs[i];
        }
        
        return nums;
        
    }
};