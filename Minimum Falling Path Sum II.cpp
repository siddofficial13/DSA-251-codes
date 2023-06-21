class Solution {
public:
    int f(int day,int last,vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n=grid.size();
        if(day==0){
            int minm=1e9;
            for(int i=0;i<n;i++){
                if(i!=last)minm=min(minm,grid[0][i]);
            }
            return minm;
        }
        if(dp[day][last]!=-1)return dp[day][last];
        int minm=1e9;
        for(int i=0;i<n;i++){
            if(i!=last){
                int cost = grid[day][i] + f(day-1,i,grid,dp);
                minm=min(minm,cost);
            }
        }
    return dp[day][last]=minm;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
         return f(n-1,n,grid,dp);
    }
};
