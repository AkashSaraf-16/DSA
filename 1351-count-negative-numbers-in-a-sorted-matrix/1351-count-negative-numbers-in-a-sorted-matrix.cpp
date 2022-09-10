class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int i = 0;
        int j = col-1;
        int count = 0 ;
        while(i<row && j>=0){           // we are starting from last col of first row because it will give us status of that particular row and col
            if(grid[i][j]<0){
                count+= row-i;          // if it is negative then all the rest col is also negative
                --j;
            }
            else{
                ++i;                // is positive we need to check the next row
            }
        }
        return count;
    }
};