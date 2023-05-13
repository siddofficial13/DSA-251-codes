#include <bits/stdc++.h> 
void inplaceRotate(vector<vector<int>> &inputArray)
{
    // Write your code here.
    int n =inputArray.size();
    //Using extra memory
    // vector<vector<int>> v(n,vector<int>(n,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         v[i][j]=inputArray[j][n-i-1];
    //     }
    // }
    // inputArray=v;
    //Without using extra memory 
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(inputArray[i][j],inputArray[j][i]);
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            swap(inputArray[i][j],inputArray[n-i-1][j]);
        }
    }
}
