class Solution {
public:
    int maxArea(vector<int>& height) {
        /*BRUTE FORCE:
        int n = height.size(), maxA = 0;
        for(int i = 0 ; i<n-1 ; i++){
            for(int j = n-1 ;j >i ; j--){
                int h = min(height[i],height[j]);
                int width = j-i;
                if(h*width > maxA)
                    maxA = h*width;
                }
            }
        return maxA;*/
        // OPTIMAL SOLUTION:
        int s = 0 , e = height.size()-1 , maxA = 0;
        int h,w;
        while(s<e){            // we are starting from end becoz area is directly proportional to width
            h = min(height[s],height[e]);   //calculating area
            w = e-s;
            maxA = max(maxA,h*w);
            if(height[s]<height[e])         // since area directly depends on min height 
                s++;
            else
                e--;
        }
        return maxA;
                                //T.C: O(N)   S.C: O(1)
        
    }
};