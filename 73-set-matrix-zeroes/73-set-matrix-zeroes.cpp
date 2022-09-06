class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();  
        int col0 = 1;
        for(int i=0 ; i < row ; i++){
                if(matrix[i][0] == 0) col0 = 0;
            for(int j=1 ; j<col ; j++){
                if(matrix[i][j] == 0){
                    // set the topmost row to 0
                    matrix[0][j] = 0;
                    // set the left most column to 0
                    matrix[i][0] = 0;
                }
            }
        }
        // going backward from bottom right so that we dont mess up our top and left most row and column respectively
        for(int i= row-1 ; i>=0 ; i--){
            for(int j=col-1 ;j>=1 ; j--)    // here j>=1 because we dont want to mess with the first column
              if(/*top row*/matrix[0][j]  == 0 || /*left column*/ matrix[i][0] == 0)
                  matrix[i][j] = 0;
              if(col0 == 0)
                  matrix[i][0] = 0;
        } 
        /*int r = matrix.size();
        int c = matrix[0].size();
        vector<int> row(r,1);
        vector<int> col(c,1);
        
        for(int i = 0 ; i<r ; i++){
            for(int j =0 ; j<c ; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;  
                }
            }
        }
        for(int i = 0 ; i < r ; i++ ){
            for(int j =0 ; j < c ; j++ ){
                if(row[i] ==0 || col[j] == 0)
                    matrix[i][j] = 0;
            }
        }
        */
    }
};