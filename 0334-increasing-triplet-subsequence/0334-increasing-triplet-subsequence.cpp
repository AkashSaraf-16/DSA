class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int fst=INT_MAX,scnd=INT_MAX;
        for(int num : nums){
            if(num<=fst){       // first filter
                fst = num;      
            }            
            else if(num<=scnd){ // second filter
                scnd = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};