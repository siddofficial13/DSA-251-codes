//52/54 tcs passed
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
           for (auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
        vector<int>dist(n,1e9);
        vector<int>countWays(n,0);
        dist[0]=0;
        countWays[0]=1;
        minHeap.push({0,0});
        int mod=(int)(1e9+7);
        while(minHeap.size()>0){
            int distance=minHeap.top().first;
            int node=minHeap.top().second;
            minHeap.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edgeCost=it.second;
                if(distance+edgeCost<dist[adjNode]){
                    dist[adjNode]=distance+edgeCost;
                    minHeap.push({distance+edgeCost,adjNode});
                    countWays[adjNode]=countWays[node];
                }
                else if(distance+edgeCost==dist[adjNode]){
                    countWays[adjNode]=(countWays[adjNode]+countWays[node])%mod;
                }
            }
        }
        return countWays[n-1];
    }
};
// #define ll long long
// #define pll pair<ll, ll>
// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pll>> graph(n);
//         for(auto& road: roads) {
//             ll u = road[0], v = road[1], time = road[2];
//             graph[u].push_back({v, time});
//             graph[v].push_back({u, time});
//         }
//         return dijkstra(graph, n, 0);
//     }
//     int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
//         vector<ll> dist(n, LONG_MAX);
//         vector<ll> ways(n);
//         ways[src] = 1;
//         dist[src] = 0;
//         priority_queue<pll, vector<pll>, greater<>> minHeap;
//         minHeap.push({0, 0}); // dist, src
//         while (!minHeap.empty()) {
//             auto[d, u] = minHeap.top(); minHeap.pop();
//             if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
//             for(auto [v, time] : graph[u]) {
//                 if (dist[v] > d + time) {
//                     dist[v] = d + time;
//                     ways[v] = ways[u];
//                     minHeap.push({dist[v], v});
//                 } else if (dist[v] == d + time) {
//                     ways[v] = (ways[v] + ways[u]) % MOD;
//                 }
//             }
//         }
//         return ways[n-1];
//     }
// };
