class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;      // stores index
        vector<int> leftSmaller,rightSmaller;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                leftSmaller.push_back(-1);
            else
                leftSmaller.push_back(st.top());
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                rightSmaller.push_back(heights.size());
            else
                rightSmaller.push_back(st.top());
            st.push(i);
        }
        reverse(rightSmaller.begin(),rightSmaller.end());
        int area=0,tempArea=0;
        for(int i=0;i<heights.size();i++){
            tempArea=(rightSmaller[i]-leftSmaller[i]-1)*(heights[i]);
            area=max(tempArea,area);
        }
        return area;
        
    }
};