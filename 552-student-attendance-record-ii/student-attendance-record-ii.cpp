class Solution {
public:
    int M = 1e9 + 7;
    
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int a = 0; a<2; a++){
            for(int l = 0; l<3; l++){
                dp[0][a][l] = 1;
            }
        }

        for(int i = 1; i<=n; i++){
            for(int a = 0; a<2; a++){
                for(int l = 0; l <3; l++){
                    long long result = dp[i-1][a][0];
                    result += ( a+1 <2 ? (dp[i-1][a+1][0] % M) : 0);
                    result += (l+1 <3 ? (dp[i-1][a][l+1] % M) : 0);

                    dp[i][a][l] = result % M;
                }
            }
        }

        return dp[n][0][0];
    }
};