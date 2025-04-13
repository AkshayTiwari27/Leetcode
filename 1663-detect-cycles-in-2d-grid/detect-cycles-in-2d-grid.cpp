class Solution {
public:
    int m, n, cycle;
    vector<vector<int>>directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(int i, int j, int px, int py, vector<vector<char>>& grid, vector<vector<int>>&color){
        color[i][j] = 1;

        for(auto& dir : directions){
            int row = i + dir[0];
            int col = j + dir[1];
            if(row == px && col == py) continue;

            if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == grid[i][j]){
                if(color[row][col] == 0){
                    dfs(row, col, i, j, grid, color);
                }
                else if(color[row][col] == 1){
                    cycle = 1;
                    break;
                }
            }
        }
        color[i][j] = 2;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>color(m, vector<int>(n, 0));

        for(int i = 0; i<m && !cycle; i++){
            for(int j = 0; j<n; j++){
                if(color[i][j] == 0){
                    dfs(i, j, -1, -1, grid, color);
                }
            }
        }

        return cycle;
    }
};