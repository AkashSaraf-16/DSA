class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> degree;
        unordered_map<int,int> leftOcc;
        unordered_map<int,int> rightOcc;
        int freq=0,min_length=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            degree[num]++;
            if(leftOcc.find(num)==leftOcc.end())
                leftOcc[num]=i;
            rightOcc[num]=i;
            if(degree[num]>freq){
                freq=degree[num];
                min_length=rightOcc[num]-leftOcc[num]+1;
            }
            else if(degree[num]==freq){
                min_length=min(min_length,rightOcc[num]-leftOcc[num]+1);
            }
        }
        return min_length;
    }
};