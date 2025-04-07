class Solution {
public:
    vector<vector<int>>directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>&visited, int i, int j){
        visited[i][j] = true;
        int m = board.size();
        int n = board[0].size();
        for(auto &dir : directions){
            int row = dir[0] + i;
            int col = dir[1] + j;
            if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && board[row][col] == 'O'){
                visited[row][col] = true;
                dfs(board, visited, row, col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));

        for(int i = 0; i<n; i++){
            if(board[0][i] == 'O'){
                dfs(board, visited, 0, i);
            }
            if(board[m-1][i] == 'O'){
                dfs(board, visited, m-1, i);
            }
        }

        for(int i = 0; i<m; i++){
            if(board[i][0] == 'O'){
                dfs(board, visited, i, 0);
            }
            if(board[i][n-1] == 'O'){
                dfs(board, visited, i, n-1);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};