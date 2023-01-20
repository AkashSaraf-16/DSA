class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        for(int i=0;i<numRows;i++){
            tri[i].resize(i+1);
            tri[i][0]=tri[i][tri[i].size()-1]=1;
            for(int j=1;j<tri[i].size()-1;j++){
                tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
            }
        }
        return tri;
    }
};