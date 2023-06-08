class Solution {
public:
       //Here question asks to return minimum time it takes for all the n nodes to receive the signal. /////Which means it wants to say that find the shortest time to reach all the nodes and then return ///////maximum time out of it.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vis(n,0);//created a visited array
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;//minHeap ds to store the node to be reached and the time taken 
        vector<int>dist(n,1e9);//distance array to maintain and update the distances
        dist[k-1]=0;//starting node
        vector<vector<int>>adj[n];//creating the adajacency list on 0 based indexing
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            vector<int>temp;
            temp.push_back(v);
            temp.push_back(times[i][2]);
            adj[u].push_back(temp);//conatins vectors in the format of {destination node,time taken}
        }
        minHeap.push({0,k-1});//pushing the src node in the minHeap
        vis[k-1]=1;//already visited the src node as it is the starting point
        while(minHeap.size()>0){
            int node=minHeap.top().second;
            int distance=minHeap.top().first;
            vis[node]=1;
            minHeap.pop();//popping out the node from the minHeap after visiting it
            for(auto it: adj[node]){
                int edge_wt=it[1];
                int adjNode=it[0];//checking for whether the distance from the current node to the adjacent node is less than the original one and accordingly updating it in the distance array
                if(distance+edge_wt<dist[adjNode]){
                    dist[adjNode]=distance+edge_wt;
                    minHeap.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans=*max_element(dist.begin(),dist.end());//maximums of the distances 
        for(int i=0;i<n;i++){
            if(!vis[i])return -1;//if some node by chance remains not to be visited then return -1
        }
        return ans;
    }
};
