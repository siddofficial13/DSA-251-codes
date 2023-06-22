#include <bits/stdc++.h> 
int mod = (int)1e9+7;
int f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(ind==0){
        if(target==0 && arr[0]==0){
            return 2;
        }
        if(target==0 || target==arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int nottaken =f(ind-1,target,arr,dp);
    int taken=0;
    if(arr[ind]<=target){
        taken = f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target] = (nottaken+taken)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(int i=0;i<n;i++){
      totsum+=arr[i];
    }
    if(totsum-d<0)return 0;
    if((totsum-d)%2==1)return 0;
    int s2= (totsum-d)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr,dp);
}


