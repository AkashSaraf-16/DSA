class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==1)
            return {nums[0]};
        list<int> l;
        vector<int> res;
        int  j=0;
        for(int i=0;i<nums.size();i++){
            while(!l.empty() && nums[i]>l.back())
                l.pop_back();
            l.push_back(nums[i]);
            if(i>=k-1){
                res.push_back(l.front());
                if(nums[j]==l.front())
                    l.pop_front();
                j++;
            }
        }
        return res;
    }
};