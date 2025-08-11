class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>>dp(m+1, vector<long long>(n+1, 0));

        for(int i= 0; i<n; i++){
            dp[m-1][i] = grid[m-1][i];
        }

        for(int i = m-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
            long long ans = LLONG_MAX;
                for(int col = 0; col < n; col++){
                    if(col != j) ans = min(ans, dp[i+1][col]);
                }

                dp[i][j] = grid[i][j] + ans;
            }
        }

        long long result = LLONG_MAX;
        for(int i = 0; i<n; i++){
            result = min(dp[0][i], result);
        }
        return result;
    }
};