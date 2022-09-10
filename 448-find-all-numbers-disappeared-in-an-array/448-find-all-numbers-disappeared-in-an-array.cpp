class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){     // we are accessing nums[i] and in that way we are checking whch values are present  
            int temp = nums[i];
            temp = temp > 0 ? temp : -1*temp;
            if(nums[temp-1] > 0)
                nums[temp-1] = -1*(nums[temp-1]);
        }
        for(int i = 0 ; i < nums.size() ; i++){     // the index which are positive are the ones who are not contained in nums so we push them in our ans
            if(nums[i] > 0 ){
                ans.push_back(i+1);
            }
        }
        return ans; 
    }
};