class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
        if(vis[node]) return;
        vis[node] = 1;
         ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) { 
                dfs(it, adj, vis, ls);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
       
        int cnt=0;
        for(int i=0;i<n;i++){
          if(!vis[i]){
              vector<int>ls;
              dfs(i,adj,vis,ls);
               int count = 0;
               for(int j=0;j<ls.size();j++){
                   if(adj[ls[j]].size()>=ls.size()-1)count++; // checking whether each node of the separate component of size n has greater than equal to n-1 edges or not 
               }
               if(count==ls.size())cnt++;  // if all the edges have that much amount of neighbouring edges then condition satisfies 
          }
        }
        
        return cnt;
    }
};
