class Solution {
public:
    int M = 1e9 + 7;

    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, 0));

        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<= n; i++){
            long long curr = 1;
            for(int j = 1; j<=k; j++){
                curr += dp[i-1][j];
                if(j >= i) curr -= dp[i-1][j-i];
                dp[i][j] = curr % M;
            }
        }

        return dp[n][k];
    }
};