class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n == 0) return dp[n] = 0;
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];

        int result = 0;
        int mini = INT_MAX;
        for(int i = 1; i*i<=n; i++){
            result = solve(n - (i*i));
            mini = min(result + 1, mini);
        }

        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};