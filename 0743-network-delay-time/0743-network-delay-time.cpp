class Solution {
public:
    // TC : Time complexity: O((N - 1)! + E \log E)O((N−1)!+ElogE)
    // Adjacency list, defined it as per the maximum number of nodes given in constraint
    // We are using an array of vector of pairs because we will store the travel time on first and destination at second on ith index where i decnotes the source
    vector<pair<int, int>> adj[101];        // for every node n : adj[n] = {{w1,m1},{w2,m2}....} where w->weight and m-> vertex
    
    void DFS(vector<int>& signalReceivedAt, int currNode, int currTime) {
        // If the current time is greater than or equal to the fastest signal received
        // Then no need to iterate over adjacent nodes
        if (currTime >= signalReceivedAt[currNode]) {
            return;
        }

        // Fastest signal time for currNode so far
        signalReceivedAt[currNode] = currTime;
        
        // Broadcast the signal to adjacent nodes
        for (pair<int, int> edge : adj[currNode]) {
            int travelTime = edge.first;
            int neighborNode = edge.second;
            
            // currTime + time : time when signal reaches neighborNode
            DFS(signalReceivedAt, neighborNode, currTime + travelTime);
        }
    }
    // TC: O(n*E)
    void BFS(vector<int>& signalReceivedAt, int currNode) {
        queue<int> q;
        // Fastest signal time for currNode so far
        q.push(currNode);
        signalReceivedAt[currNode] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // Broadcast the signal to all adj nodes
            for(pair<int,int> edge : adj[cur]){
                int time = edge.first;
                int neighborNode = edge.second;
                int arrivalTime = signalReceivedAt[cur] + time;
                if (signalReceivedAt[neighborNode] > arrivalTime) {
                    // Fastest signal time for neighborNode so far
                    // signalReceivedAt[currNode] + time : 
                    // time when signal reaches neighborNode
                    signalReceivedAt[neighborNode] = arrivalTime;
                    q.push(neighborNode);                
                }
            }
        }
    }
    // TC: O(ElogN)
    void dijkstra(vector<int>& signalReceivedAt, int source){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        signalReceivedAt[source] = 0;
        while(!pq.empty()){
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if(currNodeTime>signalReceivedAt[currNode])
                continue;
            for(pair<int,int> edge:adj[currNode]){
                int timeToReach = edge.first;
                int neighborNode = edge.second;
                if(timeToReach+currNodeTime<signalReceivedAt[neighborNode]){
                    signalReceivedAt[neighborNode] = currNodeTime+timeToReach;
                    pq.push({signalReceivedAt[neighborNode],neighborNode});
                }
            }
                
        }
        
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }
        // Sort the edges connecting to every node on basis of the travel time
        // TC: O(NlogE) N-vertex E-Edge
        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        vector<int> signalReceivedAt(n + 1, INT_MAX);
        //DFS(signalReceivedAt, k, 0);
        // BFS(signalReceivedAt, k);
        dijkstra(signalReceivedAt,k);
        int answer = INT_MIN;
        for (int node = 1; node <= n; node++) {
            cout<<signalReceivedAt[node]<<endl;
            answer = max(answer, signalReceivedAt[node]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};