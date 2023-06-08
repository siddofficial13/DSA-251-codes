class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m =heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        minHeap.push({0,{0,0}});
        while(minHeap.size()>0){
            int difference=minHeap.top().first;
            int row=minHeap.top().second.first;
            int col=minHeap.top().second.second;
            minHeap.pop();
            if(row==n-1 && col==m-1){
                return difference;
            }
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                    int nextDifference= max(abs(heights[newrow][newcol]-heights[row][col]),difference);
                    if(nextDifference<dist[newrow][newcol]){
                        dist[newrow][newcol]=nextDifference;
                        minHeap.push({nextDifference,{newrow,newcol}});
                    }
                }
            }
        }
        return 0;
    }
};
