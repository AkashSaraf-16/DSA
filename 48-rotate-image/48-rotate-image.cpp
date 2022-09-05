class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
  /*   vector<vector<int>> r = matrix;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                r[j][r.size()-1-i] = matrix[i][j];
            }
        }
        matrix = r;     */
    // trick : first reverse the matrix and the swap it diagonally    
        reverse(matrix.begin() ,matrix.end());
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j =i+1 ; j < matrix[0].size() ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    } 
        
};