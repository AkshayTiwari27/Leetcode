class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>>directions = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, 0)));


        for(int k = 1; k<= maxMove; k++){
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    for(auto &dir :directions){
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if (nr < 0 || nc < 0 || nr >= m || nc >= n){
                            dp[i][j][k] = (dp[i][j][k]+1) % M;
                        }
                        else{
                            dp[i][j][k] = (dp[i][j][k]+ dp[nr][nc][k-1]) % M;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};