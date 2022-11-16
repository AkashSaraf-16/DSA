class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lb(height.size());
        vector<int> rb(height.size());
        int total = 0;
        
        int lmax = height[0];   
        lb[0] = height[0];
        for(int i = 1 ; i < height.size() ; i++){
            lmax = max(lmax,height[i]);
            lb[i] = lmax;
        }
        
        int rmax = height[height.size()-1];
        rb[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2 ; i >= 0 ; i--){
            rmax = max(rmax,height[i]);
            rb[i] = rmax;
        }
        for(int i = 0 ; i < height.size() ; i++){
            total = total + min(lb[i],rb[i]) - height[i] ;
        }
        return total;
    }
};