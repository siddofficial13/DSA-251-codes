class Solution {
public:
    int f(int ind,int k, string &s,vector<vector<int>> &dp,int n){
        if(k==n)  return 1;
        if(ind>=s.size()) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int pick=f(ind,k+1,s,dp,n);
        int notpick=f(ind+1,k,s,dp,n);
        return dp[ind][k]=pick+notpick;
    }
    int countVowelStrings(int n) {
        // string s="aeiou";
       
        // vector<vector<int>>dp(s.size(),vector<int>(n+1,-1));
        // return f(0,0,s,dp,n);
        string s = "aeiou";
        vector<vector<int>> dp(s.size(), vector<int>(n + 1, 0));

        // Initialize base cases
        for (int i = 0; i < s.size(); i++)
            dp[i][1] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < s.size(); i++) {
                for (int j = i; j < s.size(); j++) {
                    dp[i][len] += dp[j][len - 1];
                }
            }
        }
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
            total += dp[i][n];
        }
        return total;

    }
};
