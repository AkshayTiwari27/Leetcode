class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i == m-1 && j == n-1 && grid[i][j] == 0) return 1;

        if(i >= m || j < 0 || i < 0 || j >= n || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(i, j+1, m, n, grid);
        int down = solve(i+1, j, m, n, grid);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0,0,m,n , obstacleGrid);
    }
};