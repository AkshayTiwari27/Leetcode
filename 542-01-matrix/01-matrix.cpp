class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        queue<vector<int>>q;
        vector<vector<int>>distance(m, vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>>directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int i = v[0];
            int j = v[1];
            int d = v[2];
            distance[i][j] = d;

            for(auto & dir: directions){
                int row = i + dir[0];
                int col = j + dir[1];
                if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]){
                    q.push({row, col, d+1});
                    visited[row][col] = true;
                }
            }
        }

        return distance;
    }
};