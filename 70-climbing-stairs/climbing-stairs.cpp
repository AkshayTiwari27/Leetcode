class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n == 0) return dp[n] = 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];


        int result = solve(n-1);
        result += solve(n-2);

        return dp[n] = result;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};