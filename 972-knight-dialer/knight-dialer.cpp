class Solution {
public:
    vector<vector<int>>adj = {
        {4,6} , {8,6}, {7,9}, {4,8}, {3,9,0}, {}, {7,1,0}, {2,6}, {1,3}, {2,4}
    };
    int MOD = 1e9 + 7;
    int dp[5001][11];
    int solve(int n, int cell){
        if(n == 0) return 1;

        int result = 0;
        if(dp[n][cell] != -1) return dp[n][cell];

        for(auto & v : adj[cell]){
            result =  (result + solve(n-1, v)) % MOD;
        }

        return dp[n][cell] = result % MOD;
    }

    int knightDialer(int n) {
        int result = 0;
        memset(dp, -1, sizeof(dp));
        for(int cell = 0; cell <= 9; cell++){
            result =  (result + solve(n-1, cell)) % MOD;
        }

        return result % MOD;
    }
};