class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,res=m+n-1;
        // Checking only for j becoz we need to process and merge until second array has something
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[res--]=nums1[i--];
            }
            else{
                nums1[res--]=nums2[j--];
            }
        }
    }
};