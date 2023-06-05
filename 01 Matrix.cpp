class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<vector<int>> distance_mat(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            pair<int, int> indices = q.front().first;
            int distance = q.front().second;
            q.pop();

            int rowth = indices.first;
            int colth = indices.second;

            distance_mat[rowth][colth] = distance;

            for(int i = 0; i < 4; i++)
            {
                int newRow = rowth + delRow[i];
                int newCol = colth + delCol[i];

                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol] && mat[newRow][newCol] == 1)
                {
                    q.push({{newRow, newCol}, distance+1});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return distance_mat;
    }
};
