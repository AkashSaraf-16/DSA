class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector <int>> ans( n, vector<int>(n) );
        int val=1;

        int sr=0 , sc = 0 , er = n-1 , ec = n-1;
        val = 1;
        while(val <= (n*n)){
            /// printing start row
            for (int i=sc ; i<=ec ; i++){
                ans[sr][i] = val;
                val++;
            }
            sr++;
            /// printing end col
            for (int i=sr ; i<=er ; i++){
                ans[i][ec] = val;
                val++;
            }
            ec--;
            /// printing end row
            for (int i=ec ; i>=sc ; i-- ){
                ans[er][i] = val;
                val++;
            }
            er--;
            /// printing start col
            for (int i=er ; i>=sr ; i--){
                ans[i][sc] = val;
                val++;
            }
            sc++;
        }
        
        return ans;        
    }
};