class Solution {
public:
    int dp[201][201];
    int solve(int i, int j, int m, int n, vector<vector<int>>&grid){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1) return dp[i][j] =  grid[i][j] + solve(i, j+1, m, n, grid);
        else if(j == n-1) return dp[i][j] =  grid[i][j] + solve(i+1, j, m, n, grid);
        else return dp[i][j] = grid[i][j] + min(solve(i, j+1, m, n, grid), solve(i+1, j, m, n, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n =grid[0].size(), m = grid.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n, grid);
    }
};