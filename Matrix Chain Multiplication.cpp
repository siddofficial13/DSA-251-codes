#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int minm = 1e9;
    for(int k=i;k<j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        if(steps<minm) minm=steps;
    }
    return dp[i][j]=minm;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N,-1));
    // return f(1,N-1,arr,dp);
    for(int i=1;i<N;i++){
        dp[i][i]=0;
    }
    for(int i=N-1; i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini,ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}
