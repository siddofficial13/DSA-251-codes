class Solution {
public:
    int f(vector<int> &nums){
        int n= nums.size();
       int prev=nums[0];
        int prev2= 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;
            int curri=max(take,nottake);
            prev2= prev;
            prev=curri;
        }
        return prev;
    }


    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>temp1,temp2;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(f(temp1),f(temp2));
    }
};

#include <bits/stdc++.h> 
long long int f(int ind,vector<long long int> &nums,vector<long long int> &dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    long long int pick = nums[ind] + f(ind-2,nums,dp);
    long long int notPick = 0+ f(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    vector<long long int>temp1,temp2;
    if(n==1)return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);
    }
     vector<long long int>dp1(temp1.size()+1,-1);
    vector<long long int>dp2(temp2.size()+1,-1);

    return max(f(temp1.size()-1,temp1,dp1),f(temp2.size()-1,temp2,dp2));

}
