#include <bits/stdc++.h> 

bool isSafe(int i, int j, int n, vector<vector<int>> &visited,vector<vector<int>> &maze){
    if((i>=0 && i<n) && (j>=0 && j<n) && visited[i][j]==0 && maze[i][j]==1){
      return true;
    }
    return false;
}

void findPath(int i, int j, vector<vector<int>> &maze, int n,vector<vector<int>> &visited,vector<vector<int>> &ans){
  //Base Case
  if(i==n-1 && j==n-1){
    vector<int>temp;
    visited[i][j]=1;
    for(int x=0;x<n;x++){
      for(int y=0;y<n;y++){
        temp.push_back(visited[x][y]);
      }
    }
    visited[i][j]=0;
    ans.push_back(temp);
    return;
  }
  visited[i][j]=1;
  //Down Move
  int I =i+1;
  int J =j;
  if(isSafe(I,J,n,visited,maze)){
    findPath(I,J,maze,n,visited,ans);
  }
  //Up Move
   I =i-1;
   J =j;
  if(isSafe(I,J,n,visited,maze)){
    findPath(I,J,maze,n,visited,ans);
  }
  //Left Move
   I =i;
   J =j-1;
  if(isSafe(I,J,n,visited,maze)){
    findPath(I,J,maze,n,visited,ans);
  }
  //Right Move
    I =i;
   J =j+1;
  if(isSafe(I,J,n,visited,maze)){
    findPath(I,J,maze,n,visited,ans);
  }
  visited[i][j]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> visited(n,vector<int>(n,0));
  vector<vector<int>> ans;
  if(maze[0][0]==0){
    return ans;
  }
  findPath(0,0,maze,n,visited,ans);

  return ans;
}
