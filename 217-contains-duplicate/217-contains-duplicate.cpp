class Solution {
public:
    // SET
    /*
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        st.insert(nums.begin(),nums.end());
        return !(st.size()==nums.size());
    }
    */
    // UNORDERED MAP
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int size=nums.size();

        unordered_map<int, int> contains;
        
        for(int i=0;i<size;i++)
        {
            contains[nums[i]]+=1;
            if(contains[nums[i]]>1)
            {
                return true;
            }
                
        }

        return false;
    }
};