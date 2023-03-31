class Solution {
public:
//     TC:O(m*n)
//     SC:O(m*n)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size(),0));
        int Max=0;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                Max=max(Max,LIP(matrix,i,j,memo));
            }
        }
        return Max;
    }
    
    int LIP(vector<vector<int>>& matrix, int r,int c,vector<vector<int>>& memo){
        if(r<0 || c<0 || r>=matrix.size() || c>=matrix[0].size())
            return 0;
        
        if(memo[r][c]>0)
            return memo[r][c];
        
        int currentMax=1;
        // down neighbour
        if(r+1<matrix.size() && r+1>=0 && matrix[r][c]<matrix[r+1][c])
            currentMax=max(currentMax,1+LIP(matrix,r+1,c,memo));
        // up neighbour
        if(r-1<matrix.size() && r-1>=0 && matrix[r][c]<matrix[r-1][c])
            currentMax=max(currentMax,1+LIP(matrix,r-1,c,memo));
        // right neighbour
        if(c+1<matrix[0].size() && c+1>=0 && matrix[r][c]<matrix[r][c+1])
            currentMax=max(currentMax,1+LIP(matrix,r,c+1,memo));
        // left neighbour
        if(c-1<matrix[0].size() && c-1>=0 && matrix[r][c]<matrix[r][c-1])
            currentMax=max(currentMax,1+LIP(matrix,r,c-1,memo));
        
        memo[r][c]=currentMax;
        return currentMax;
    }
};