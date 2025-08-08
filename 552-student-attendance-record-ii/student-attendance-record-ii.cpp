class Solution {
public:
    int M = 1e9 + 7;
    int dp[100001][2][3];
    int solve(int n, int a, int l){
        if(a >= 2 || l >=3) return 0;
        if(n == 0) return 1;

        if(dp[n][a][l] != -1) return dp[n][a][l];
        int A = solve(n-1, a+1, 0);
        int P = solve(n-1, a, 0);
        int L = solve(n-1, a, l + 1);

        return dp[n][a][l] = (((A + P) % M) + L) % M;
    }
    int checkRecord(int n) {

        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0) % M;
    }
};