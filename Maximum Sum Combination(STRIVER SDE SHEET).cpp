#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			minHeap.push(a[i]+b[j]);
			if(minHeap.size()>k){
				minHeap.pop();
			}
		}
	}
	vector<int>ans;
	while(minHeap.size()>0){
		ans.push_back(minHeap.top());
		minHeap.pop();
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	return ans;
}
