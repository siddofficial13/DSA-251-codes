#include<bits/stdc++.h>
class DisjointSet {
   
public: 
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
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
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
    DisjointSet ds(n*m);
    vector<vector<int>>vis(n,vector<int>(m,0));
    int count=0;
    vector<int>ans;
    for(auto it:q){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]){
            ans.push_back(count);
            continue;
        }
        vis[row][col]=1;
        count++;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int adjRow=row+delrow[i];
            int adjCol=col+delcol[i];
            if(adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m){
                if(vis[adjRow][adjCol]){
                    if(ds.findUPar(row*m+col)!=ds.findUPar(adjRow*m+adjCol)){
                        count--;
                        ds.unionByRank(row*m+col, adjRow*m+adjCol);
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}
