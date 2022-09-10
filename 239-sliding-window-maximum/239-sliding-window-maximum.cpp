class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 1)     return nums;
        list<int> mx;
        vector<int> ans;
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            while(!mx.empty() && nums[i] > mx.back())   //calculation
                mx.pop_back();
            mx.push_back(nums[i]);
            if(i >= k-1){                   // when window size is reached
                ans.push_back(mx.front());  // process the result done during the calculation
                if(mx.front() == nums[j])   // processing the letf window incase it is the largest we have to remove the calculaion
                    mx.pop_front();
                j++;                        // keeping track of our left pointer
            }
        }
        return ans;
    }
};