class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> nge;      // next gretest element; maintaining it to hold the next greatest element on top
        map<int,int> mp;
        int n = nums2.size();
        for(int i = n-1 ; i >= 0 ; i--){
            while(!nge.empty() && nge.top() < nums2[i]){    //  maintaining for nums2[i] greater on top
                nge.pop();
            } 
            if(nge.empty()){
                mp[nums2[i]] = -1;          // no greater exist
            }
            else
                mp[nums2[i]] = nge.top();   // greater on the top
            
            nge.push(nums2[i]);             // assuming this is greater for next itertaion
        }
        vector<int> ans;
        for(auto it : nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};