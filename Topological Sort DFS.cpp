#include <bits/stdc++.h> 

void dfs(vector<vector<int>> &adj, vector<int> &vis, stack<int> &s, int node){
    // Base Case
   
    vis[node] = 1;
    for(int v : adj[node]){
        if(!vis[v]){
            dfs(adj, vis, s, v);
        }
    }
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);

    }
    vector<int>vis(v,0);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(adj,vis,s,i);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
