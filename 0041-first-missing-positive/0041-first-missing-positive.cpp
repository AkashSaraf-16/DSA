class Solution {
public:
    // Using hashmap
    // TC:O(nlogn) SC:O(n)
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        map<int,bool> map;
        for(int i=1;i<=n;i++)
            map.insert({i,false});
        
        for(auto i:nums){
            if(i>0 && map.count(i))
                map[i]=true;
        }
        
        for(auto a:map){
            if(a.second==false)
                return a.first;
        }
        return n+1;
    }
};