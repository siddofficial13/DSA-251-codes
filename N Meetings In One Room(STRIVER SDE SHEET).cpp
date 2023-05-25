#include <bits/stdc++.h> 

bool comp(const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) {

    if(a.first<b.first){
         return true;
    }
    else if(a.first>b.first){
        return false;
    } 
    else if(a.second.second<b.second.second){
         return true;
    }
    else{
        return false;
    } 
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++){
        v.push_back({end[i],{start[i],i+1}});
    }
    sort(v.begin(),v.end(),comp);
    int t=-1;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(v[i].second.first>t){
            ans.push_back(v[i].second.second);
            t=v[i].first;
        }
    }
    return ans;
}
