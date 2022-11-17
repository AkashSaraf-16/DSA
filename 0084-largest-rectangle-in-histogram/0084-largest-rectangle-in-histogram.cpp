class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> NSL,NSR;
        vector<int> indexL,indexR;
        
        for(int i = 0 ; i < heights.size() ; i++){
            while(!NSL.empty() && heights[NSL.top()] >= heights[i])
                NSL.pop();              // finding the next smallest element
            if(NSL.empty())
                indexL.push_back(-1);   // if not found -1
            else
                indexL.push_back(NSL.top());     // else index of that number
            
            NSL.push(i);       // pushing in stack current element and its index
        }
        for(int i = heights.size()-1 ; i >= 0 ; i--){
            while(!NSR.empty() && heights[NSR.top()] >= heights[i])
                NSR.pop();              // finding the next smallest element
            if(NSR.empty())
                indexR.push_back(heights.size());   // if not found -1
            else
                indexR.push_back(NSR.top());     // else index of that number
            
            NSR.push(i);       // pushing in stack current element and its index
        }
        reverse(indexR.begin() , indexR.end());     // reversing ths becoz we have filled it from right to left
        // indexR[indexR.size()-1] = indexR.size();    // next samllest to corner element will be this only
        vector<int> width;
        for(auto i =0 ; i< indexR.size() ; i++)
            width.push_back(indexR[i] - indexL[i] - 1) ;    // getting the width
        int maxArea = INT_MIN;
        for(int i = 0 ; i < heights.size() ; i++){
            maxArea = max(maxArea,width[i]*heights[i]);
        }
        return maxArea;
    }
};