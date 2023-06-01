#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int>ans;
	priority_queue<int>maxheap;
	priority_queue<int,vector<int>,greater<int>>minheap;
	for(int i=0;i<n;i++){
       maxheap.push(arr[i]);
	   if(maxheap.size()>k){
		   maxheap.pop();
	   }
	}
	ans.push_back(maxheap.top());
	for(int i=0;i<n;i++){
       minheap.push(arr[i]);
	   if(minheap.size()>k){
		   minheap.pop();
	   }
	}
	ans.push_back(minheap.top());
	return ans;
}
