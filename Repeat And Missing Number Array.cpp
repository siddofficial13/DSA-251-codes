#include <bits/stdc++.h>
#define ll long long
pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
	// Write your code here 
	// vector<int>v;
	// for(int i=0;i<n;i++){
	// 	v.push_back(i+1);
	// }
	// int actsum=((n)*(n+1))/2;
	// int sum=0;
	// for(int i=0;i<n;i++){
	// 	sum+=arr[i];
	// }
	// int miss=0;
	// int rep=0;
	// sort(arr.begin(),arr.end());
	// for(int i=0;i<n;i++){
	// 	if(arr[i]!=i+1 && arr[i]!=arr[i-1]){
	// 		miss=i+1;
	// 		break;
	// 	}
	// 	if(arr[i]!=i+1 && arr[i]==arr[i-1]){
	// 		rep=arr[i];
	// 		break;
	// 	}
	// }

	// if(rep==0){
	// 	return {miss,sum+miss-actsum};
	// }
	// else{
	// 	return {actsum-sum+rep,rep};
	// }
    pair<int,int>ans;
	ll num = n;
    ll S=(num*(num+1))/2;
    ll P=(num*(num+1)*(2*num+1))/6;
    ll miss=0, rep=0;         
    for(int i=0;i<A.size();i++){    
	    S-=(ll)A[i];    
		P-=(ll)A[i]*(ll)A[i];  
	}
    miss=(S+P/S)/2;
    rep=miss-S;
    ans.first=miss;    
    ans.second=rep; 
    return ans;
}
