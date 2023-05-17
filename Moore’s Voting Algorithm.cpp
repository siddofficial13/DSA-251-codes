#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int N = floor(n/2);
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	int ans;

	bool flag = false;
	for(auto itr :mp){
		if(itr.second>N){
			flag=true;
            ans = itr.first;
            break;
		}
	}
	if(flag){
		return ans;
	}
	else{
		return -1;
	}
}
