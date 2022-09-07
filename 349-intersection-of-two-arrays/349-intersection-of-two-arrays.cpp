// class Solution {
// public:
    // TC: O(nlogn) SC: O(1)
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin() , nums1.end());
//         sort(nums2.begin() , nums2.end());
//         vector<int> ans;
//         int i = 0 , j = 0;
//         while(i < nums1.size() && j < nums2.size()){
//             if(nums1[i] == nums2[j]){
//                 if(ans.size() == 0 || ans.back() != nums1[i])
//                     ans.push_back(nums1[i]);
//                 else{
//                     i++;
//                     j++;
//                 }
//             }
//             else if(nums1[i] < nums2[j]){
//                 i++;
//             }
//             else
//                 j++;
//         }
//         return ans;
//     }
// };
// Approch 2:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};