class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        vector<int> h(matrix[0].size());
        for(int i=0;i<matrix[0].size();i++)
            h[i]=matrix[0][i]=='0'?0:1;
        maxArea=largestRectangleArea(h);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                h[j]=matrix[i][j]=='0'?0:1+h[j];
            maxArea=max(maxArea,largestRectangleArea(h));
        }
        return maxArea;
    }
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