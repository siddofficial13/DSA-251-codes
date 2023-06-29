class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp=nums;
        reverse(temp.begin(),temp.end());
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp1[prev]>dp1[i]){
                    dp1[i]=1+dp1[prev];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(temp[prev]<temp[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
        }
    //    for(int i=n-1;i>=0;i--){
    //         for(int prev=n-1;prev>i;prev--){
    //             if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
    //                 dp2[i]=1+dp2[prev];
    //             }
    //         }
    //     }
        reverse(dp2.begin(),dp2.end());
        int maxm=1;
        for(int i=0;i<n;i++){
            if(dp1[i]==1||dp2[i]==1) continue;
            maxm=max(maxm,dp1[i]+dp2[i]-1);
        }

        return n-maxm;
// here  for bitonic subsequence the maximum length maxm

    }
};
