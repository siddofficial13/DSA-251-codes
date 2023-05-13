#include <bits/stdc++.h> 
bool isMatrixSymmetric(vector<vector<int>> matrix){
    // Write your code here. 
    int n = matrix.size();
    // vector<vector<int>> v1(n,vector<int> (n,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         v1[i][j]=matrix[j][i];
    //     }
    // }
    int count=0;
    //Using extra space in O(n2) time
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(matrix[i][j]==v1[i][j]){
    //             count++;
    //         }
    //     }
    // }
    // if(count==n*n){
    //     return true;
    // }
    // else{
    //     return false;
        
    // }//Without Using extra space
    for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(matrix[i][j]==matrix[j][i]){
                  count++;
              }
          }
      }
      if(count==n*n){
          return true;
      }
      else{
          return false;
    }
}
