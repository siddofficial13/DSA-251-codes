// #include <bits/stdc++.h> 
// vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int src) {
//     // Write your code here.
//     vector<vector<int>>adj[V];
//     for(auto ele:vec){
//         vector<int>t1={ele[2],ele[0]};
//         vector<int>t2={ele[2],ele[1]};
//         adj[ele[0]].push_back(t2);
//         adj[ele[1]].push_back(t1);
//     }
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
//     vector<int>distance(V,INT_MAX);
//     distance[src]=0;
//     minHeap.push({0,src});
//     while(minHeap.size()>0){
//         int node=minHeap.top().second;
//         int dis=minHeap.top().first;
//         minHeap.pop();
//         for(auto it:adj[node]){
//             int v=it[0];
//             int w=it[1];
//             if(dis+v<distance[w]){
//                 distance[w]=dis+v;
//                 minHeap.push({dis+v,w});
//             }
//         }
//     }
//     return distance;
// }
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int src) {
    vector<int> dis(V, INT_MAX);
    vector<pair<int, int>> adj[V];
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // first min heap
    // pq.push({0, 0});
    dis[0] = 0;
    for(auto ele : vec){
        adj[ele[0]].push_back({ele[1], ele[2]});
        adj[ele[1]].push_back({ele[0], ele[2]});
    }
    // while(!pq.empty()){
    //     pair<int, int> node = pq.top();
    //     pq.pop();
    //     vector<pair<int, int>> nodes = adjList[node.second];
    //     for(auto ele: nodes){
    //         int ndis = node.first + ele.second;
    //         if(ndis < dis[ele.first]){
    //             dis[ele.first] = ndis;
    //             pq.push({ndis, ele.first});
    //         }
    //     }
        
    // }
    
    
    // return dis;
    //Using set
    set<pair<int,int>>st;
    st.insert({0,src});
    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;
        int dist=it.first;
        st.erase(it);
        for(auto it: adj[node]){
            int adjNode=it.first;
            int edgW=it.second;
            if(dist+edgW<dis[adjNode]){
                if(dis[adjNode]!=INT_MAX){
                    st.erase({dis[adjNode],adjNode});
                }
                dis[adjNode]=dist+edgW;
                st.insert({dis[adjNode],adjNode});
            }
        }
    }
    return dis;

}
