class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, int n ,vector<vector<int>> &dp, int fee){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,prices,n,dp,fee), 0 + f(ind+1,1,prices,n,dp,fee));
        }
        else{
            profit = max(prices[ind]-fee+f(ind+1,1,prices,n,dp,fee),0+f(ind+1,0,prices,n,dp,fee));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,n,dp,fee);
    }
};
