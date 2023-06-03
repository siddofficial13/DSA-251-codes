//Code Studio Problem Code
#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int>>adj(vertex);
    for(auto e:edges){
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }
    int n = edges.size();
    int vis[vertex]={0};;
    // vis[0]=1;
    // queue<int>q;
    // q.push(0);
    vector<int>bfs;
    // bfs.push_back(0);
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(!vis[node]){
                    vis[node]=1;
                    bfs.push_back(node);
                    for(auto j:adj[node]){
                        if(!vis[j]){
                            q.push(j);
                        }
                    }
                }
            }
        }
    }
    return bfs;

}
//Striver Code Link
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        // push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};
