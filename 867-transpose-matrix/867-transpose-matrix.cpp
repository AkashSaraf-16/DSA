class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix[0].size() , vector<int>(matrix.size() , 0 )); // init of 2D vector
        for(int i = 0 ; i < matrix.size() ; i++ ){
            for(int j =0 ; j< matrix[0].size() ; j++){
                temp[j][i] = matrix[i][j];
            }
        }
        return temp;
        
    }
};