class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color,int sourceColor,int &row,int &col){
        // base comdition
        image[sr][sc] = color;
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto direction:directions){
            int r=sr+direction[0],c=sc+direction[1];
            if(r>=0 && r<row && c>=0 && c<col && image[r][c]==sourceColor){
                image[r][c]=color;
                helper(image,r,c,color,sourceColor,row,col);
            }
        }
    }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sourceColor = image[sr][sc];
        if(sourceColor==color)
            return image;
        int row=image.size(),col=image[0].size();
        helper(image,sr,sc,color,sourceColor,row,col);
        return image;
    }
};