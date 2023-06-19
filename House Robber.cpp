#include<bits/stdc++.h>
int f(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick = nums[ind] + f(ind-2,nums,dp);
    int notPick = 0+ f(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}
int maxMoneyLooted(vector<int> &nums, int n)
{
	/*
		Write your code here.
		Don't write main().
	 	Don't take input, it is passed as function argument.
	 	Don't print output.
	 	Taking input and printing output is handled automatically.
	*/
	vector<int>dp(nums.size()+1,-1);
    return f(nums.size()-1,nums,dp);

}
