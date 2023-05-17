#include <bits/stdc++.h> 
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
	// Write your code here.
	vector<vector<int>> v(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			v[i][(j+k)%m]=mat[i][j];
		}
	}
	vector<int>ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans.push_back(v[i][j]);
		}
	}
	return ans;
	
}
