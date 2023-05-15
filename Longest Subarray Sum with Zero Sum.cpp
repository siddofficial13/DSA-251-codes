#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int n = arr.size();
    map<int,int>mp;// to store the sum and the index
    int maxm=0;
    int sum=0;
    for(int i=0;i<n;i++){
      sum=sum+arr[i];
      if(sum==0){
        maxm=i+1;
      }
      else{
        if(mp.find(sum)!=mp.end()){
          maxm=max(maxm,i-mp[sum]);
        }
        else{
          mp[sum]=i;
        }
      }
    }
    return maxm;
    
}
