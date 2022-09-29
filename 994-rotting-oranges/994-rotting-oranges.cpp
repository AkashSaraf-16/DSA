class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        bool anyRotten=false;
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){      // storing all the rotten oranges as starting point of our traversal;
                    q.push({{i,j},0});
                    vis[i][j]=2;        // since this index is visited and it is rotten hence setting to it 2
                    anyRotten=true;
                }
            }
        }
        int time=INT_MIN;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(auto d:directions){
                int newx=x+d[0];
                int newy=y+d[1];
                if(newx>=0 && newx<m && newy>=0 && newy<n && vis[newx][newy]!=2 && grid[newx][newy]==1){    // we will do BFS for those index only which are not alreday visited and rotten (i.e., fresh ones only)
                    q.push({{newx,newy},t+1});
                    vis[newx][newy]=2;      //since now this is also rotten hence 2
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                    return -1;
            }
        }
        return anyRotten?time:0;
    }
};