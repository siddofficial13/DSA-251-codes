class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        minHeap.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(minHeap.size()>0){
            int stopCount=minHeap.top().first;
            int node=minHeap.top().second.first;
            int cost=minHeap.top().second.second;
            minHeap.pop();
            if(stopCount>k)continue;
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edgeCost=it.second;
                if(cost+edgeCost<dist[adjNode] && stopCount<=k){
                    dist[adjNode]=cost+edgeCost;
                    minHeap.push({stopCount+1,{adjNode,cost+edgeCost}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};
