#include<bits/stdc++.h>

int countSmallerThanMid(vector<int> &row,int mid){
  int lo=0;
  int hi=row.size()-1;
  while(lo<=hi){
    int md = (lo+hi)/2;
    if(row[md]<=mid){
      lo=md+1;
    }
    else{
      hi=md-1;
    }
  }
  return lo;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m= matrix[0].size();
    int lo=1;
    int hi=1e9;
    while(lo<=hi){
    int mid = (lo+hi)/2;
    int cnt=0;
    for(int i=0;i<n;i++){
      cnt+=countSmallerThanMid(matrix[i],mid);
    }
    if(cnt<=((n*m)/2)){
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }
  return lo;
    // vector<int>v;
    // for(int i=0;i<n;i++){
    //   v.push_back(matrix[i][m/2]);
    // }
    // sort(v.begin(),v.end());
    // return v[n/2];
}
