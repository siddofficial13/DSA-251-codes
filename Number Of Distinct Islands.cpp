#include<bits/stdc++.h>

void dfs(int row,int col, int** arr,vector<vector<int>> &vis,vector<pair<int,int>> &vec,int row0,int col0,int n,int m){
    vis[row][col]=1;
    vec.push_back({row-row0,col-col0});
    int delrow[]={-1, 0, 1, 0};
    int delcol[]={0, 1, 0, -1};
     for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && arr[nrow][ncol] == 1) {
                dfs(nrow, ncol, arr, vis, vec, row0, col0,n,m); 
            }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]==1){
                vector<pair<int,int>>vec;
                dfs(i,j,arr,vis,vec,i,j,n,m);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
