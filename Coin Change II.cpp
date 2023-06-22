//Memoisation Approach

#include<bits/stdc++.h>
long f(int ind,int value,int * denominations, vector<vector<long>> &dp){
    if(ind==0){
        if(value%denominations[0]==0)return 1;
        return 0;
    }
    if(dp[ind][value]!=-1)return dp[ind][value];
    long nottake=0+f(ind-1,value,denominations,dp);
    long take=0;
    if(denominations[ind]<=value){
      take=f(ind,value-denominations[ind],denominations,dp);
    }
    return dp[ind][value]=take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}
