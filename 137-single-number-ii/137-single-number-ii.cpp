class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 0;      // we will work on bit level
        int res = 0 ;
        for(int i = 0 ; i < 32 ; i++){  // checking every bit of no.s
            count = 0;                  // setting it 0 for next iteration
            for(int j = 0 ; j <nums.size() ; j++){
                int currbit = (nums[j]>>i)&1;   // if nums current(ith) bit is set count it
                if(currbit == 1)
                    count++;
            }
            count= count % 3;           // since no.s are in triplet we will % the count
            if(count!= 0){              // if count is not 0 means ans has its bit set at current index
                res|= (1<<i);       // res+= (1<<i) is also acceptable we will add them considering the current index power like for 0 index factor will be 1 for 1st -> 2 for 2nd-> 4 
            } 
        }
        return res;
    }
};