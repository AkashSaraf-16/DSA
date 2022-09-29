class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res;
        int indRed=0,indWhite=0,indBlue=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                res.insert(res.begin()+indRed,0);
                indRed++;
            }
            else if(nums[i]==1){
                res.insert(res.begin()+indRed+indWhite,1);
                indWhite++;
            }
            else{
                res.insert(res.begin()+indRed+indWhite+indBlue,2);
                indBlue++;
            }
        }
        nums=res;
    }
};