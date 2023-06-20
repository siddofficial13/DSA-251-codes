class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int leftdiagonal = matrix[i][j];
                if(j-1>=0)leftdiagonal+=dp[i-1][j-1];
                else leftdiagonal+=1e9;
                 int rightdiagonal = matrix[i][j];
                if(j+1<n)rightdiagonal+=dp[i-1][j+1];
                else rightdiagonal+=1e9;
                dp[i][j]=min(up,min(leftdiagonal,rightdiagonal));
            }
        }
        int maxm=INT_MAX;
        for(int j=0;j<n;j++){
            maxm=min(maxm,dp[n-1][j]);
        }
        return maxm;
    }
};
