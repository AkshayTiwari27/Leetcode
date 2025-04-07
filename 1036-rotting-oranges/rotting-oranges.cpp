class Solution {
public:
    vector<vector<int>>directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n,false));

        queue<vector<int>>q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2 && !visited[i][j]){
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int r = v[0];
            int c = v[1];
            int t = v[2];
            time = max(time, t);

            for(auto &dir : directions){
                int row = r + dir[0];
                int col = c + dir[1];
                if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1 && !visited[row][col]){
                    visited[row][col] = true;
                    q.push({row, col, t+1});
                }
            }
        }

        for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(grid[i][j] == 1 && !visited[i][j]) return -1;
                }
        }

        return time;

    }
};