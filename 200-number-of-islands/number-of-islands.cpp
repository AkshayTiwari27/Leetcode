class Solution {
public:
    vector<vector<int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&visited, int i, int j){
        visited[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();

        for(auto& dir:directions){
            int row = dir[0] + i;
            int col = dir[1] + j;
            if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && grid[row][col] == '1'){
                visited[row][col] = true;
                dfs(grid, visited, row, col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};