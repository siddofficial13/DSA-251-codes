#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<arr.size();i++){
		int sum=0;
		for(int j=i;j<arr.size();j++){
            sum+=arr[j];
			if(minHeap.size()<k){
				minHeap.push(sum);
			}
			else{
				if(minHeap.top()<sum){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();
}
