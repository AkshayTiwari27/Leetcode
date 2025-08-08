class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>>adj = {{4,6}, {6,8},{7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};

    int dp[5001][11];

    int solve(int n, int cell){
        if(n == 0) return 1;

        if(dp[n][cell] != -1) return dp[n][cell];

        int result = 0;

        for(auto &v : adj[cell]){
            result = (result + solve(n-1, v)) % M;
        }
        return dp[n][cell] = result;
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int result = 0;

        for(int i = 0; i<= 9; i++){
            result = (result + solve(n-1, i)) % M;
        }

        return result;
    }
};