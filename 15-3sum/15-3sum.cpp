class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() < 3)
            return {};
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
// method 1 : using hashmap
        unordered_map<int,int> mp;       // we will store the the ele and its last index of occurence to avoid duplicate enteries
        for(int i = 0 ; i<nums.size() ; i++)
            mp[nums[i]] = i;
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            if(nums[i] > 0 ){           // first element in sorted array is itself 0 then no need to proceed
                break;
            }
            for(int j = i+1 ; j < nums.size() - 1 ; j++){
                int target = -1*(nums[i] + nums[j]);
                if(mp.count(target) && mp.find(target)->second > j){/* if there is compliment of the sums and which is grtr than present index of j becoz we can only consider those elements which we havent picked so far*/               
                    ans.push_back({nums[i] , nums[j] , target}); 
                }  
                j = mp.find(nums[j])->second ;       // last occurence of 2nd fixed element
            }
            i = mp.find(nums[i])->second ;   // last occurence of 1st fixed element
        }
// method 2 : using two pointer
     /*   for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1])           // skip if we start the loop with same value 
                continue;
            int  l = i+1 , r = nums.size() - 1;
            while(l<r){
                if(nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else {
                    ans.push_back({nums[i],nums[l],nums[r]});  
                    int last_l = nums[l];
                    int last_r = nums[r];
                        while(l<r && nums[l] == last_l)        // to skip duplicate entries
                             l++;
                        while(l<r && nums[r] == last_r)        // to skip duplicate entries
                             r--;  
                }
             
            }
        }*/
        return ans;
        }
};