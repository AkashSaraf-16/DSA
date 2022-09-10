class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> degree;
        unordered_map<int,int> leftOcc;
        unordered_map<int,int> rightOcc;
        int freq = 0 , minLength = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            degree[num]++;
            if(leftOcc.find(num) == leftOcc.end())   //if no leftOcc till now we are handling this case becoz we need to 1st find the left index and right index to calc minLength  
                leftOcc[num] = i;
            rightOcc[num] = i;
            
            if(degree[num] > freq){                 // if degree of num > freq then we can simply store it and update the minLEngth and freq
                freq = degree[num];
                minLength = rightOcc[num]-leftOcc[num] + 1;
            }
            else if(degree[num] == freq){           // but if they are equal then we need to go with that subarray that has less length
                minLength = min(minLength , rightOcc[num]-leftOcc[num] + 1);
            }
                
            
        }
        return minLength;
    } 
};