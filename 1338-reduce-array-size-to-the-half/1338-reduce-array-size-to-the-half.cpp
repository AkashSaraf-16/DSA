class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr)    ++mp[it];
        
        vector<int> frequencies;
        for(auto [_ , freq]: mp)    frequencies.push_back(freq);    // here are storing the freq of elements onlt i.e mp[x] so auto [_ , freq] this means we are not interested in first value which is key in map rather store freq in map in frequenscies
        sort(frequencies.begin() , frequencies.end());
        
        int ans = 0 , removed = 0 , half = arr.size()/2 , i = frequencies.size()-1;
        while(removed<half){
            ans += 1;
            removed+= frequencies[i--];
        }
        return ans;
    }
};