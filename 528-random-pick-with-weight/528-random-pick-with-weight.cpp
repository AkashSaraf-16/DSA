class Solution {
public:
    // TC:O(N) SC:O(N)
    // we will make prefix sum of given array and generate the number between 0 - total sum-1 then we will use uppperbound to get the nearrest greater or equal index 
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i = 1; i < w.size() ; i++){
            prefixSum.push_back(w[i]+prefixSum[i-1]);
        }
    }
    
    int pickIndex() {
        // factor will be anything between 0 - totalsum of array-1
        int factor = rand()%prefixSum[prefixSum.size()-1];      // rand : will generate from 0-32767(if we dont specify limits)
        // upper bound will generate the index which will be greater than or equal to factor
        std::vector<int>::iterator it = upper_bound(prefixSum.begin() , prefixSum.end() , factor);
        return it - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */