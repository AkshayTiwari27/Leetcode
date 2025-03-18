class Solution {
public:
    int dp[100001][2][3];
    int MOD = 1e9 + 7;

    int solve(int n, int absence, int consecutive_late){
        if(absence >=2 || consecutive_late >= 3) return 0;

        if(n == 0) return 1;

        if(dp[n][absence][consecutive_late] != -1) return dp[n][absence][consecutive_late];

        int A = solve(n - 1, absence + 1, 0) % MOD;
        int P = solve(n - 1, absence, 0) % MOD;
        int L = solve(n - 1, absence, consecutive_late + 1) % MOD;

        return dp[n][absence][consecutive_late] = ((A + P) % MOD + L) % MOD; 
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0);
    }
};