#include <bits/stdc++.h> 
// int coverageOfMatrix(vector<vector<int>> &mat) {
//     // Write your code here.
//     int n =mat.size();
//     int m =mat[0].size();
//     int count=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(mat[i][j]==0){
//                 if(i==0 && j==0){
//                    count+=(mat[i+1][j]+mat[i][j+1]);
//                 }
//                 else if(i==0 && j==m-1){
//                     count+=(mat[i+1][j]+mat[i][j-1]);
//                 }
//                 else if(i==0){
//                      count+=(mat[i+1][j]+mat[i][j-1]+mat[i][j+1]);
//                 }
//                 else if(j==0 && i==n-1){
//                     count+=(mat[i][j+1]+mat[i-1][j]);
//                 }
//                 else if(j==0){
//                     count+=(mat[i+1][j]+mat[i-1][j]+mat[i][j+1]);
//                 }
//                 else if(i==n-1 && j==m-1){
//                     count+=(mat[i][j-1]+mat[i-1][j]);
//                 }
//                 else if(i==n-1){
//                     count+=(mat[i-1][j]+mat[i][j-1]+mat[i][j+1]);
//                 }
//                 else if(j==m-1){
//                     count+=(mat[i][j-1]+mat[i-1][j]+mat[i+1][j]);
//                 }
//                 else{
//                     count+=(mat[i][j+1]+mat[i][j-1]+mat[i+1][j]+mat[i-1][j]);
//                 }
//             }
//         }
//     }
//     return count;
// }
int coverageOfMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                if (i > 0)
                    count += mat[i - 1][j]; // Check top element
                if (i < n - 1)
                    count += mat[i + 1][j]; // Check bottom element
                if (j > 0)
                    count += mat[i][j - 1]; // Check left element
                if (j < m - 1)
                    count += mat[i][j + 1]; // Check right element
            }
        }
    }

    return count;
}
