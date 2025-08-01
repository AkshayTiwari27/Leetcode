class Solution {
public:
    int dp[20];
    int solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int result = 0;
        for(int i = 1; i<=n; i++){
            result += solve(n-i) * solve(i-1);
        }
        return dp[n] = result;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};