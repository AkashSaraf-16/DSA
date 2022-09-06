class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x=-1,y=-1,xcount=0,ycount=0;
        for(int num : nums){
            if(x == num){
                xcount++;
            }
            else if(y == num){
                ycount++;
            }
            else if(xcount == 0){
                x = num;
                xcount++;
            }
            else if(ycount == 0){
                y = num;
                ycount++;
            }
            else{
                xcount--;
                ycount--;
            }
        }
        xcount = 0;
        ycount = 0;
        for(int num : nums){
            if(num == x){
                xcount++;
            }
            else if(num == y){
                ycount++;
            }
        }
        vector<int> ans;
        if(xcount>nums.size()/3)    ans.push_back(x);
        if(ycount>nums.size()/3)    ans.push_back(y);

        return ans;
    }
};