//Memoisation Approach

class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, int n ,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,prices,n,dp), 0 + f(ind+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[ind]+f(ind+1,1,prices,n,dp),0+f(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,prices.size(),dp);
    }
};

//Tabulation
   int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                  if(buy){
            profit = max(-prices[ind]+dp[ind+1][0], 0 + dp[ind+1][1]);
        }
        else{
            profit = max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
        }
         dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

//Space Optimisation

long getMaximumProfit(long *Arr, int n)
{
    //Write your code here
    
    vector<long> ahead (2,0);
    vector<long> cur(2,0);
    
    //base condition
    ahead[0] = ahead[1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+ahead[0], -Arr[ind] + ahead[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy]  = profit;
        }
        
        ahead = cur;
    }
    return cur[0];
}
