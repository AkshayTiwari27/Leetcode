class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][1001];
    
    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i<= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= k; j++){
                int result = 0;
                for(int in = 0; in <= min(j, i-1); in++){
                    result= (result +  dp[i-1][j-in] ) % MOD;
                }
                dp[i][j] = result % MOD;
                }
            
        }

        return dp[n][k];
    }
};