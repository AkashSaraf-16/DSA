class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lb(height.size());
        vector<int> rb(height.size());
        int total = 0;
        // for every bar getting its left longest bar including it
        int lmax = height[0];   
        lb[0] = height[0];
        for(int i = 1 ; i < height.size() ; i++){
            lmax = max(height[i],lmax);
            lb[i] = lmax;
        }
        // for every bar getting its right longest bar including it
        int rmax = height[height.size()-1];
        rb[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2 ; i >= 0 ; i--){
            rmax = max(height[i],rmax);
            rb[i] = rmax;
        }
        // calculating the area per bar
        for(int i = 0 ; i < height.size() ; i++){
            total = total + min(lb[i],rb[i]) - height[i] ;
        }
        return total;
    }
};