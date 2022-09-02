class Solution {
public:
    // It is a classic Topological Sort problem where we can apply Kahn's Algorithm:
    // Creating the adjency list
    vector<int> adj[2001];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1:Processing the input so that we can have an adjency list
        for(auto edge : prerequisites){
            int source = edge[1];
            int dest = edge[0];
            adj[source].push_back(dest);
        }
        for(int i=0 ; i<numCourses ;i++){
            cout<<i<<"->";
            for(int a: adj[i])
                cout<<a<<"->";
            cout<<endl;
        }
        // Step 2:Storing the indigree 
        vector<int> indegree(numCourses,0);
        for(int i=0 ; i<numCourses ;i++){
            for(int v: adj[i]){
                indegree[v]++;
            }
        }
        for(int a:indegree)
            cout<<a<<" ";
        // Step 3: Do a BFS traversal of the graph and inc the count whenever we process a vertex if at last we are unable to process all the vertex than there is some loop.
        int count = 0;
        queue<int> q;
        for(int i = 0 ; i < numCourses ;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                --indegree[v];
                if(indegree[v] == 0)
                    q.push(v);
            }
        count++;
        }
        
        return count==numCourses;
    }
};