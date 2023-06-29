class Solution {
public:
    int f(int ind, int prev_ind, vector<int> &nums, int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len = 0 + f(ind+1, prev_ind, nums,n,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len = max(len,1+f(ind+1,ind,nums,n,dp));
        }
        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // // return f(0,-1,nums,n,dp);
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
        //         int len = 0  + dp[ind+1][prev_ind+1];
        //          if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
        //     len = max(len,1+dp[ind+1][ind+1]);
        // }
        // dp[ind][prev_ind+1] = len;
        //     }
        // }
        // return dp[0][0];
        // vector<int>dp(n,1);
        // int maxm = 1;
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<i;prev++){
        //         if(nums[prev]<nums[i]){
        //             dp[i]=max(dp[i],1+dp[prev]);
        //         }
        //     }
        //     maxm=max(maxm,dp[i]);
        // }
        // return maxm;
        vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
              int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
              temp[ind] = nums[i];
            }
        }
        return len;
    }

};
