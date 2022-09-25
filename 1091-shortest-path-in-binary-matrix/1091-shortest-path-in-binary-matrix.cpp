class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // here we have to use BFS as we can get the path more effeciently as compared to DFS
        if(grid[0][0] == 1)
            return -1;
        if(grid[0][0] == 0 && grid.size() == 1)
            return 1;
        
        queue<pair<pair<int,int>,int>> q; // (co-ordinates),length
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid.size(),false));   // to avooid going back to the same coordinate where we came from 
        
        // entering the initial conditions
        q.push({{0,0},1});
        visited[0][0] = true;
        
        
        
        while(!q.empty()){
            pair<int,int> p = q.front().first;
            
            int x = p.first;
            int y = p.second;
            int lengthOfPath = q.front().second;
            
            q.pop();
            // all possible movement we can do 
            vector<pair<int,int>> neighbours = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
            // trying all possible movement 1 by 1 
            for(pair<int,int> neighbour : neighbours){
                int newx = neighbour.first + x;
                int newy = neighbour.second + y;
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy] == 0 && !visited[newx][newy]){
                    // pushing all possible coordinates possible to move on
                    q.push({{newx,newy},lengthOfPath+1});
                    // marking that coordinates visited
                    visited[newx][newy] = true;
                    // if we reach the end then we have got the shortest path already
                    if(newx == grid.size()-1 && newy == grid[0].size()-1)
                        return lengthOfPath+1;
                }
            }
        }
        return -1;
    }
};