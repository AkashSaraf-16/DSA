class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
            st.push(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            st.push(nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};