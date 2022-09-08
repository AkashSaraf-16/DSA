class NumMatrix {
public:
    vector<vector<int>> t;  //declaring a 2d vector 
    int r;
    int c;
    NumMatrix(vector<vector<int>>& matrix) {
        //a = matrix;  // assign matrix to 'a'.
        r = matrix.size();
        c = r>0 ? matrix[0].size() : 0;
        t = vector<vector<int>>(r+1,vector<int>(c+1,0));
        for(int i = 1 ; i <= r ; i++){
            for(int j = 1 ; j <= c; j++){
                t[i][j] = matrix[i-1][j-1] + t[i-1][j] + t[i][j-1] - t[i-1][j-1]; 
            }
        }
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = t[row2+1][col2+1] - t[row1][col2+1] - t[row2+1][col1] + t[row1][col1];
    return sum;
    
   /*
   bruteforce:
   for(int i=row1;i<=row2;i++) // traverses each row from row1 to row2
    {
        
        sum=accumulate(a[i].begin()+col1,a[i].begin()+col2+1,sum);
		//calculates sum  for each row and stores it into variable 'sum'
    }
    return sum; */
    
}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */