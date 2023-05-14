#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m =matrix[0].size();
	//Using extra space
	// vector<int>rows;
	// vector<int>cols;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(matrix[i][j]==0){
	// 			rows.push_back(i);
	// 			cols.push_back(j);
	// 		}
	// 	}
	// }
	// for(int i=0;i<rows.size();i++){
	// 	for(int j=0;j<m;j++){
	// 		matrix[rows[i]][j]=0;
	// 	}
	// }
	// for(int i=0;i<cols.size();i++){
	// 	for(int j=0;j<n;j++){
	// 		matrix[j][cols[i]]=0;
	// 	}
	// }	
	bool temp =false;
	for(int i=0;i<n;i++){
		if(matrix[i][0]==0){
			temp=true;
		}
	}
    for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				matrix[0][j]=0;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[0][j]==0 || matrix[i][0]==0){
				matrix[i][j]=0;
			}
		}
	}
	if(matrix[0][0]==0){
		for(int j=0;j<m;j++){
			matrix[0][j]=0;
		}
	}
	if(temp){
		for(int i=0;i<n;i++){
			matrix[i][0]=0;
		}
	}

}
