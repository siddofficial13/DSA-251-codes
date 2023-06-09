#include <bits/stdc++.h> 
vector<pair<pair<int,int>,int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,vector<vector<int>>>adj;
    for(auto it:g) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>vis(n+1,0);
    vector<pair<pair<int,int>,int>>ans;
    // v = {weight,source,destination}
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
    minHeap.push({0,-1,1});
    while(minHeap.size()>0) {
        auto node=minHeap.top();
        minHeap.pop();
        int weight=node[0],source=node[1],destination=node[2];
        if(vis[destination]==1) {
            continue;
        }
        vis[destination]=1;
        if(source!=-1) {
            ans.push_back({{source,destination},weight});
        }
        for(auto it:adj[destination]) {
            if(!vis[it[0]]) {
                minHeap.push({it[1],destination,it[0]});
            }
        }
    }
    return ans;
}
//Minimum Cost MST
class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};
