class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(int i=0;i<points.size();i++){
           int dis=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
           vector<int>t={points[i][0],points[i][1]};
           maxHeap.push({dis,t});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
         vector<vector<int>>ans;
    while(maxHeap.size()>0){
        vector<int>temp;
        temp.push_back(maxHeap.top().second[0]);
        temp.push_back(maxHeap.top().second[1]);
        ans.push_back(temp);
        maxHeap.pop();
    }
    return ans;
    }
   
};
