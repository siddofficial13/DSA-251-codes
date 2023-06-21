class Solution {
public:
    bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target==0)return true;
    if(ind==0)return (arr[0]==target);
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool nottake=f(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target) take=f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=take | nottake;
}
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        	int totsum=0;
	for(int i=0;i<n;i++){
		totsum+=arr[i];
	}
	if(totsum%2==1)return false;
	else{
		int k=totsum/2;
		vector<vector<int>>dp(n,vector<int>(k+1,-1));
		return f(n-1,k,arr,dp);
	}
    }
};
