class Solution {
public:
    // TC : O(N) SC:O(1)
    // dry run with this example : 12453654
    void nextPermutation(vector<int>& nums) {
             int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {      // step 1 : find non decreasing no.
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());  // already largest number
    	} else {
    	    for (l = n - 1; l > k; l--) {   // step 2: find a no. on right just greater to it
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);         // swap them
    	    reverse(nums.begin() + k + 1, nums.end());  // reverse it after k+1 index to get just greater number
        }
    }
};