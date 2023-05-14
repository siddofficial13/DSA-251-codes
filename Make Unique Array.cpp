#include <bits/stdc++.h> 
int minElementsToRemove(vector<int> &arr)
{
	// Write your code here.
	int n = arr.size();
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
	return n-s.size();
}
