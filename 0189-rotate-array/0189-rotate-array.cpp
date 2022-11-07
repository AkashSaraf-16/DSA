class Solution {
public:
    void func1(vector<int>& nums,int k){
        // TC:O(N) SC:O(N)
        int n=nums.size();
        vector<int> temp(n,0);
        int j=0;
        for(int i=n-k;i<n;i++){
            temp[j]=nums[i];
            j++;
        }
        for(int i=0;i<n-k;i++){
            temp[j]=nums[i];
            j++;
        }
        nums=temp;
    }
    void rotateBy1(vector<int>& nums){
        // TC:O(N) SC:O(1)
        int n = nums.size();
        int temp=nums[n-1];
        for(int i=nums.size()-1;i>=1;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=temp;
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        func1(nums,k);
        // for(int i=1;i<=k%nums.size();i++)
            // rotateBy1(nums);
    }
};