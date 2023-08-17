class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
int n=specialRoads.size();
        
       //Make a graph like 
       //first connect start and end nodes.
       //now connect every specialroads starting and ending poinnts speartely to the start and the target
       // specifically if u->v is a speecial road then following combinations
       //u->start && start->u;
       //v->start && start->v;
       //u->target && target->u;
       //v->target && target->v;
       //store the distances as well
       //mp-{startx,starty,{cost,{endx,endy}}}
        map<pair<int,int>,vector<pair<int,pair<int,int>>>> mp;

        mp[{start[0],start[1]}].push_back({(abs(target[0]-start[0])+abs(target[1]-start[1])),{target[0],target[1]}});
        mp[{target[0],target[1]}].push_back({(abs(target[0]-start[0])+abs(target[1]-start[1])),{start[0],start[1]}});
        for(int i=0;i<n;i++){
            auto it=specialRoads[i];
            
            mp[{it[0],it[1]}].push_back({(abs(start[0]-it[0])+abs(start[1]-it[1])),{start[0],start[1]}});
            mp[{start[0],start[1]}].push_back({(abs(start[0]-it[0])+abs(start[1]-it[1])),{it[0],it[1]}});
            
            
            mp[{it[2],it[3]}].push_back({(abs(start[0]-it[2])+abs(start[1]-it[3])),{start[0],start[1]}});
            mp[{start[0],start[1]}].push_back({(abs(start[0]-it[2])+abs(start[1]-it[3])),{it[2],it[3]}});
            
            
            mp[{it[0],it[1]}].push_back({(abs(target[0]-it[0])+abs(target[1]-it[1])),{target[0],target[1]}});
            mp[{target[0],target[1]}].push_back({(abs(target[0]-it[0])+abs(target[1]-it[1])),{it[0],it[1]}});
            
           
            mp[{it[2],it[3]}].push_back({(abs(target[0]-it[2])+abs(target[1]-it[3])),{target[0],target[1]}});
            mp[{target[0],target[1]}].push_back({(abs(target[0]-it[2])+abs(target[1]-it[3])),{it[2],it[3]}});
            
            //special road is unidirectiobnal as mentioned in the question
            mp[{it[0],it[1]}].push_back({(min(it[4],abs(it[0]-it[2])+abs(it[1]-it[3]))),{it[2],it[3]}});
            for(int j=i+1;j<n;j++){
                auto nit=specialRoads[j];    
                // u to u1(bidirectionally)
                mp[{it[0],it[1]}].push_back({(abs(it[0]-nit[0])+abs(it[1]-nit[1])),{nit[0],nit[1]}});
                mp[{nit[0],nit[1]}].push_back({(abs(it[0]-nit[0])+abs(it[1]-nit[1])),{it[0],it[1]}});
                
                // u to v1(bidirectionally)
                mp[{it[0],it[1]}].push_back({(abs(it[0]-nit[2])+abs(it[1]-nit[3])),{nit[2],nit[3]}});
                mp[{nit[2],nit[3]}].push_back({(abs(it[0]-nit[2])+abs(it[1]-nit[3])),{it[0],it[1]}});
                
                // v to u1(bidirectionally)
                mp[{it[2],it[3]}].push_back({(abs(it[2]-nit[0])+abs(it[3]-nit[1])),{nit[0],nit[1]}});
                mp[{nit[0],nit[1]}].push_back({(abs(it[2]-nit[0])+abs(it[3]-nit[1])),{it[2],it[3]}});
                
                // v to v1(bidirectionally)
                mp[{it[2],it[3]}].push_back({(abs(it[2]-nit[2])+abs(it[3]-nit[3])),{nit[2],nit[3]}});
                mp[{nit[2],nit[3]}].push_back({(abs(it[2]-nit[2])+abs(it[3]-nit[3])),{it[2],it[3]}}); 
            }
        }
        //implementing djikstras algorithm
       map<pair<int,int>,int>vis; //{i->j,0/1}
       map<pair<int,int>,int>dis;  //{i->j,cost}
       //minHeap-> {cost,i->j}
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
       minHeap.push({0,{start[0],start[1]}});
       while(minHeap.size()){
           auto it = minHeap.top();
           minHeap.pop();
           int cost=it.first;
           auto node = it.second;
           if(!vis[node]){
               dis[node]=cost;
               vis[node]=1;
               for(auto it1:mp[node]){
                   if(!vis[it1.second]){
                       minHeap.push({cost+it1.first,{it1.second}});
                   }
               }
           }
       }
       return dis[{target[0],target[1]}];
    }
};
