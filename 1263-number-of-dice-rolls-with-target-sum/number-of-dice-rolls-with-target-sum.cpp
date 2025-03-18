class Solution {
public:
    long long MOD = 1e9 + 7;
    int dp[31][1001];
    
    int numRollsToTarget(int n, int a, int target) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= target; k++){
                int ways = 0;
                for(int i = 1; i <= a; i++){
                    if(k>=i)
                        ways = (ways + dp[j-1][k - i]) % MOD;
                }

               dp[j][k] = ways;
            }
        }

        return dp[n][target];
    }
};