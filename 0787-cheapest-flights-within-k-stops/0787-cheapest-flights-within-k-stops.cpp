class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // here we have to use modified version of dijkstra's algo
        vector<pair<int,int>> adj[n];
        // Creating the adjacency list
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;       // stops,node,weight
        q.push({0,{src,0}});
        while(!q.empty()){
            auto frnt=q.front();
            q.pop();
            int stops=frnt.first;
            int node=frnt.second.first;
            int weight=frnt.second.second;
            if(stops>k) continue;
            for(auto neighbour:adj[node]){
                int neighbourNode=neighbour.first;
                int neighbourWeight=neighbour.second;
                if(weight+neighbourWeight<dist[neighbourNode]){
                    dist[neighbourNode]=weight+neighbourWeight;                 
                    q.push({stops+1,{neighbourNode,weight+neighbourWeight}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }

};