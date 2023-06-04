class Solution {
public:
void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[src] = true;
        
        for(int i=0; i<isConnected[src].size(); i+=1) {
            if(isConnected[src][i] == 1 && visited[i] == false) {
                dfs(i, isConnected, visited);
            }
        }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        // vector<int>adjLs;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             adjLs[i].push_back(j);
        //             adjLs[j].push_back(i);
        //         }
        //     }
        // }
      vector<bool>visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    }
};
