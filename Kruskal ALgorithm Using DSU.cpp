#include <bits/stdc++.h> 
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1,1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            // size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<pair<int,pair<int,int>>>edges;
	// for(int i=0;i<n;i++){
		for(auto it: graph){
			int node=it[0];
			int adjNode=it[1];
			int edgeWt=it[2];
			edges.push_back({edgeWt,{node,adjNode}});
		}
	// }
	DisjointSet ds(n);
	sort(edges.begin(),edges.end());
	int mstWt=0;
	for(auto it: edges){
		int u=it.second.first;
		int v=it.second.second;
		int wt=it.first;
		//Checking for whether we have connected u and v or not if not connected then we need to take that edge
		//and connect it by any of the following be it union by size or by union of rank.
		if(ds.findUPar(u)!=ds.findUPar(v)){
			mstWt+=wt;
			ds.unionBySize(u,v);
		}
	}
	return mstWt;
}
