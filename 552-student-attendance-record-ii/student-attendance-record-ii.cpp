class Solution {
public:
    int dp[100001][2][3];
    int MOD = 1e9 + 7;

    int checkRecord(int n) {
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                dp[0][i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int A = 0; A <= 1; A++) {
                for (int L = 0; L <= 2; L++) {

                    long result = dp[i - 1][A][0]; // solve(n-1, absent, 0)
                    result += (L + 1 <= 2 ? dp[i - 1][A][L + 1] : 0); // solve(n-1, A, L+1)
                    result += (A + 1 <= 1 ? dp[i - 1][A + 1][0] : 0); // solve(n-1, A+1, 0)

                    dp[i][A][L] = result % MOD;
                }
            }
        }

        return dp[n][0][0];
    }
};