//Recursive Code
void solve(int oldColor, int newColor, int x, int y, int n, int m, vector<vector<int>> &image){
    if(x < 0 || x >= n || y < 0 || y >= m || image[x][y] != oldColor){
        return;
    }

    image[x][y] = newColor;

    solve(oldColor, newColor, x+1, y, n, m, image);
    solve(oldColor, newColor, x-1, y, n, m, image);
    solve(oldColor, newColor, x, y+1, n, m, image);
    solve(oldColor, newColor, x, y-1, n, m, image);

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];

    if(oldColor == newColor){
        return image;
    }

    int n = image.size();
    int m = image[0].size();

    solve(oldColor, newColor, x, y, n, m, image);

    return image;
}
//DFS CODE
class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,int color,int iniColor){
        ans[row][col]=color;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n =image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol] !=color){
                dfs(nrow,ncol,ans,image,color,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};
