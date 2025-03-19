class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001]; // Memoization table

    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));

        // Base case: Only one way to arrange numbers with 0 inverse pairs (sorted order)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // DP computation using prefix sum optimization
        for (int i = 1; i <= n; i++) {  // Number of elements
            for (int j = 1; j <= k; j++) {  // Inverse pairs
                dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0)) % MOD;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};
