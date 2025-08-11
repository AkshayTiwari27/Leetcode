class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> prev(m, vector<int>(n, 0)), curr(m, vector<int>(n, 0));

        for (int k = 1; k <= maxMove; k++) {
            // Reset curr for the current move count
            for (int i = 0; i < m; i++) {
                fill(curr[i].begin(), curr[i].end(), 0);
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto &dir : directions) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        
                        if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                            curr[i][j] = (curr[i][j] + 1) % M;
                        } else {
                            curr[i][j] = (curr[i][j] + prev[nr][nc]) % M;
                        }
                    }
                }
            }
            prev = curr;
        }

        return prev[startRow][startColumn];
    }
};
