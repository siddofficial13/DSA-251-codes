//codestudio
#include<bits/stdc++.h>
void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
void dfs3(vector<int> &temp,int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        temp.push_back(node);
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(temp,it, vis, adjT);
            }
        }
}    
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>adj[n];
    vector<int>adjT[n];
    for(auto it: edges){
      adj[it[0]].push_back(it[1]);
    //   adjT[it[1]] = {it[0]};
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    for(int i=0;i<n;i++)vis[i]=0;
     for(auto it: edges){
      adjT[it[1]].push_back(it[0]);
    //   adjT[it[1]] = {it[0]};
    }
    vector<vector<int>>ans;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            vector<int>temp;
            dfs3(temp,node, vis, adjT);
            ans.push_back(temp);
        }
    }
    return ans;
}
//striver
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
}
