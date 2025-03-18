class Solution {
public:
    vector<vector<int>>adj = {
        {4,6} , {8,6}, {7,9}, {4,8}, {3,9,0}, {}, {7,1,0}, {2,6}, {1,3}, {2,4}
    };
    int MOD = 1e9 + 7;

    int dp[5001][11];
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));

        for(int cell = 0; cell <= 9; cell++){
            dp[0][cell] = 1;
        }

        for(int i = 1; i < n; i++ ){
            for(int cell = 0; cell <= 9; cell++){
                int ans = 0;
                for(auto &v: adj[cell]){
                    ans = (ans + dp[i-1][v] )% MOD;
                }
                dp[i][cell] = ans;
            }
        }


        int result = 0;
        for(int i = 0; i <= 9; i++){
            result = (result + dp[n-1][i]) % MOD;
        }
        return result;
        
    }
};