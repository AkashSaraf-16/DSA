class Solution {
public:
    vector<int> getRow(int rowIndex) {
        ++rowIndex;
        vector<vector<int>> ans(rowIndex); // an array with numRows to store ans
        for(int i=0 ; i<rowIndex; i++ ){
            ans[i].resize(i+1);
            ans[i][i] = ans[i][0] = 1; // setting leftmost and rightmost entry in row to 1
            for(int j =1 ; j<i; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans[rowIndex-1];
    }
};