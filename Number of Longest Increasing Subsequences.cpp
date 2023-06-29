class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>ct(n,1);
        int maxm=1;
        for(int i=0;i<=n-1;i++){
            for(int prev_index =0;prev_index<=i-1; prev_index++){
                if(nums[prev_index]<nums[i] && dp[prev_index]+1>dp[i]){
                    dp[i] = dp[prev_index] + 1;
                    ct[i] = ct[prev_index];
                }
                else if(nums[prev_index]<nums[i] && dp[prev_index]+1==dp[i]){
                    ct[i] = ct[i] + ct[prev_index];
                }
            }
            maxm=max(maxm,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<=n-1;i++){
            if(dp[i]==maxm)cnt+=ct[i];
        }
        return cnt;
    }
};
