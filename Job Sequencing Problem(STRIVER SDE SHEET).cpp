#include <bits/stdc++.h> 

static bool cmp(vector<int> &a,vector<int> &b){
    return a[1]>b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),cmp);
    int n = jobs.size();
    int sum=0;
    vector<int> v(10000,-1);
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(v[j]==-1){
                v[j]=i;
                sum+=jobs[i][1];
                break;
            }
        }
    }
    return sum;
}
