class Solution {
public:
    int dp[301][301];
    int M = 1e9 + 7;
    int solve(int n, int num, int x){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(pow(num, x) > n) return 0;

        if(dp[n][num] != -1) return dp[n][num];

        int take = solve(n- pow(num, x), num+1, x) %M;
        int skip = solve(n, num+1, x)%M;

        return dp[n][num] =  (take + skip)%M;
    }
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 1, x);
    }
};