//CodeStudio Code
#include<bits/stdc++.h>

void dfssolve(vector<vector<int>> &adj,vector<int> &temp,vector<int> &vis,int node){
    if(vis[node])return;
    vis[node]=1;
    temp.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfssolve(adj,temp,vis,it);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(V);
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>>dfs;
    vector<int>vis(V,0);
    //since graph is disconnected
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int>temp;
            dfssolve(adj,temp,vis,i);
            dfs.push_back(temp);
        }
    }
    return dfs;
}
//Striver Code
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};
