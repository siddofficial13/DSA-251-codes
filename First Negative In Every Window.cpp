#include<bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
	int start=0;
	int end=0;
	deque<int> ans;
	vector<int> res;
	while(end<n){
		if(arr[end]<0){
			ans.push_back(arr[end]);
		}
		if(end-start+1<k){
			end++;
		}
		else if(end-start+1==k){
			if(ans.size()==0){
				res.push_back(0);
			}
			else {
				res.push_back(ans.front());
				if(arr[start]<0) ans.pop_front();
			}
			start++;
			end++;
		}
	}
	return res;
}
