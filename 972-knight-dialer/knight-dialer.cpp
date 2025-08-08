class Solution {
public:
    vector<vector<int>>adj = {
        {4,6} , {8,6}, {7,9}, {4,8}, {3,9,0}, {}, {7,1,0}, {2,6}, {1,3}, {2,4}
    };
    int MOD = 1e9 + 7;

    int knightDialer(int n) {
        vector<vector<int>>dp(n+1, vector<int>(11, 0));

        for(int i = 0; i<11; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int cell = 0; cell <= 9; cell++){
                int result = 0;

                for(auto & v : adj[cell]){
                    result =  (result + dp[i-1][v]) % MOD;
                }

                dp[i][cell] = result % MOD;
            }
        }

        int result = 0;

        for(int cell = 0; cell <= 9; cell++){
            result = (result + dp[n-1][cell]) % MOD;
        }

        return result;
    }
};