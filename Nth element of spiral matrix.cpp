#include <bits/stdc++.h> 
int findKthElement(vector<vector<int>> matrix, int k) {
    // Write your code here.
    vector<int>v;
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    int left=0;
    int right=nCols-1;
    int top=0;
    int bottom=nRows-1;
    while(top<=bottom && left<=right){
         for(int i=left;i<=right;i++){
             v.push_back(matrix[top][i]);
         }
         top++;
         for(int i=top;i<=bottom;i++){
             v.push_back(matrix[i][right]);
         }
         right--;
         if(top<=bottom){
             for(int i=right;i>=left;i--){
                 v.push_back(matrix[bottom][i]);
             }
             bottom--;
         }
         if(left<=right){
             for (int i = bottom; i >= top; i--) {
                   v.push_back(matrix[i][left]);
                }
                left++;
         }
    }
    return v[k-1];
}
