#include <bits/stdc++.h> 
int f(int ind,vector<int> &heights,vector<int> &dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left = f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)right=f(ind-2,heights,dp)+ abs(heights[ind]-heights[ind-2]);
    return dp[ind]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
  vector<int>dp(n,0);
  dp[0]=0;
  for(int i=1;i<n;i++){
      int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
      int ss=INT_MAX;
      if(i>1){
          ss=dp[i-2]+abs(heights[i]-heights[i-2]);
      }
      dp[i]=min(fs,ss);
  }
  return dp[n-1];
}
