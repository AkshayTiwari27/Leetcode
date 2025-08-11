class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i<n; i++){
            dp[m-1][i] = grid[m-1][i];
        }

        for(int i = m-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int mini = INT_MAX;
                if(i+1 < m && j-1 >=0)
                mini = min(mini, grid[i][j] + dp[i+1][j-1]);

                if(i+1 < m)
                mini = min(mini, grid[i][j] + dp[i+1][j]);

                if(i+1 < m && j+1 < n)
                mini = min(mini, grid[i][j] + dp[i+1][j+1]);

                dp[i][j] = mini;
            }
        }

        int result = INT_MAX;
        for(int i = 0; i<n; i++){
            result = min(dp[0][i], result);
        }

        return result;
    }
};