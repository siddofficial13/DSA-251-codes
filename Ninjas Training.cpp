#include<bits/stdc++.h>

int f(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxm=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxm=max(maxm,points[0][task]);
            }
        }
        return maxm;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxm=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + f(day-1,task,points,dp);
            maxm=max(maxm,point);
        }
    }
    return dp[day][last]=maxm;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
