class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1,maxArea=0;
        while(s<e){
            int w=e-s,h=min(height[e],height[s]);
            maxArea=max(maxArea,h*w);
            if(height[s]<height[e])
                s++;
            else
                e--;
        }
        return maxArea;
    }
};