class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n == 0) return 0;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int result = INT_MAX;
        for(int i = 1; i*i <=n; i++){
            result = min(result, 1 + solve(n - (i*i)));
        }
        return dp[n] = result;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};