class Solution {
public:
    // TC: O(log(min(m,n)))   SC:O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())   return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size();
        int n=nums2.size();
        int l=0,h=m;
        while(l<=h){
            int cut1=(l+h)/2;       // partition for nums1 array
            int cut2=(n+m+1)/2-cut1;    // partition for nums2 array
            int l1= cut1==0?INT_MIN:nums1[cut1-1];
            int l2= cut2==0?INT_MIN:nums2[cut2-1];
            int r1= cut1==m?INT_MAX:nums1[cut1];
            int r2= cut2==n?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                // if we got the right partition
                if((m+n)%2==0)      // even
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else                // odd
                    return max(l1,l2);
            }
            else if(l1>r2){
                h=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
};