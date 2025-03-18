class Solution {
public:
    vector<vector<int>>adj = {
        {4,6} , {8,6}, {7,9}, {4,8}, {3,9,0}, {}, {7,1,0}, {2,6}, {1,3}, {2,4}
    };
    int MOD = 1e9 + 7;

    int dp[5001][11];
    int solve(int n, int i){
        if(n == 0) return dp[n][i] = 1;
        int ans = 0;
        if(dp[n][i] != -1) return dp[n][i];
        for(auto &v: adj[i]){
            ans = (ans + solve(n-1, v) )% MOD;
        }
        return dp[n][i] = ans;
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int result = 0;
        for(int i = 0; i <= 9; i++){
            result = (result + solve(n-1, i)) % MOD;
        }
        return result;
        
    }
};