class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     /*int sum = m+n;
        for(int i = m ; i<sum ; i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin() , nums1.end()); */
      if(n == 0)    return;
      else if( m == 0 ) {
          nums1 = nums2;
          return;
      }
      int i = 0 , j = 0 , k = 0;
      vector<int> ans(m+n,0);
      while(i<m && j<n) {
          if(nums1[i] <= nums2[j]){
              ans[k] = nums1[i];
              i++;
              k++;
          }
          else{
              ans[k] = nums2[j];
              j++;
              k++;
          }
      }
      while(i<m){
          ans[k] = nums1[i];
          k++;
          i++;
      }
      while(j<n){
          ans[k] = nums2[j];
          k++;
          j++;
      }
     nums1 = ans;
        
    }
};