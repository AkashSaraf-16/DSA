class Solution {
public:
    // typical connected parts problem 
    // TC:O(N*M) SC:O(N*M)
    void bfs(vector<vector<char>> grid,vector<vector<int>> &vis,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> pq;
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        vis[row][col]=1;
        pq.push({row,col});
        while(!pq.empty()){
            int r=pq.front().first;
            int c=pq.front().second;
            pq.pop();
            for(auto direction:directions){     // traversing the neighbours
                int nrow=r+direction[0];
                int ncol=c+direction[1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol] =='1'){
                   pq.push({nrow,ncol});
                   vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){ // we want to do traversal only for 1(land)
                    res++;
                    cout<<i<<" "<<j<<endl;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return res;
    }
};