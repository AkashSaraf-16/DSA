class Solution {
public:
//     TC:O(No. of Stops)
//     SC:O(N)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> stopBusMap;
        for(int i=0;i<routes.size();i++){
            for(int j:routes[i])
                stopBusMap[j].push_back(i);      // mapping a stop with buses
        }
        queue<pair<int,int>> bfs;               // <stop,no. of buses changed>
        bfs.push({source,0});
        unordered_set<int> visited;
        visited.insert(source);
        while(!bfs.empty()){
            int stop=bfs.front().first ,trip=bfs.front().second;
            bfs.pop();
            if(stop==target)
                return trip;
            for(int bus:stopBusMap[stop]){          // finding the bus which picks from this stop
                for(int stop:routes[bus]){         // finding the stops which the above bus takes to
                    if(visited.find(stop) == visited.end()){       // if we have never been to this stop
                        visited.insert(stop);
                        bfs.push({stop,trip+1});
                    }   
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};