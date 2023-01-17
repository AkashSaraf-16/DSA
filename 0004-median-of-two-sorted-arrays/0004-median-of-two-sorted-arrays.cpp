class Solution {
public:
    // Naive Approach
    // TC:O((m+n)/2) SC:O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int mid=((m+n)/2)+1;
        int i=0,j=0;
        int curr=0,prev;
        for(int x=0;x<mid;x++){
            if(i==m){
                prev=curr;
                curr=nums2[j];
                j++;
            }
            else if(j==n){
                prev=curr;
                curr=nums1[i];
                i++;                
            }
            else if(nums1[i]<nums2[j]){
                prev=curr;
                curr=nums1[i];
                i++;                
            }
            else{
                prev=curr;
                curr=nums2[j];
                j++;
            }
        }
        if((m+n)%2)
            return curr;
        return 
            (prev+curr)/2.0;
    }
};