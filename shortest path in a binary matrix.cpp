class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n =grid.size();
        int m =grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0)return 1;
        int delrow[]={0,0,1,1,1,-1,-1,-1};
        int delcol[]={1,-1,0,1,-1,0,1,-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>minHeap;
        dist[0][0]=0;
        minHeap.push({1,{0,0}});
        int pathlength=0;
        while(minHeap.size()>0){
          int distance =minHeap.top().first;
          int row=minHeap.top().second.first;
          int col=minHeap.top().second.second;
          minHeap.pop();
          for(int i=0;i<8;i++){
              int newrow=row+delrow[i];
              int newcol=col+delcol[i];
              if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==0 && distance+1<dist[newrow][newcol]){
                  dist[newrow][newcol]=1+distance;
                  if(newrow==n-1 && newcol==m-1){
                      return 1+distance;
                  }
                  minHeap.push({1+distance,{newrow,newcol}});
              }
          }
        }
        return -1;
    }
};
