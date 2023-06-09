int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>>grid(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          if (i == j) {
            grid[i][j] = 0;
          }
        }
    }
    for(auto it:edges){
        grid[it[0]][it[1]]=it[2];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
            if(i!=k && j!=k && grid[i][k]!=1e9 && grid[k][j]!=1e9) {
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 			if (grid[i][j] == 1e9) {
	// 				grid[i][j] = -1;
	// 			}
	// 		}
	// 	}
    return grid[src][dest];
}

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};
