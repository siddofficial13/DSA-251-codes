#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	// Write your code here.
	int i=0;
	int j=n-1;
	int count =0;
	// for(int i=0;i<n-1;i++){
	// 	int x= target -arr[i];
	// 	int y= lower_bound(arr.begin()+i+1,arr.end(),x)-arr.begin();
	// 	int z= upper_bound(arr.begin()+i+1,arr.end(),x)-arr.begin();
	// 	count+=z-y;
	// }
	while(i<j){
		if(arr[i]+arr[j]==target){
			count++;
			i++;
			j--;
		}
		else if(arr[i]+arr[j]<target){
			i++;
		}
		else{
			j--;
		}
	}
	if(count==0){
		return -1;
	}
	else {
		return count;
	}
}
