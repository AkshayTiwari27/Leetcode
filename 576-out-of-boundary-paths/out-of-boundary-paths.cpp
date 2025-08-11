class Solution {
public:
    int dp[51][51][51];
    int M = 1e9 + 7;
    vector<vector<int>>directions = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
    int solve(int m, int n, int maxMove, int i, int j){
        if(i < 0 || i>=m || j<0 || j>= n) return 1;

        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        if(maxMove == 0) return 0;
        int result = 0;
        for(auto &dir : directions){
            int nr = i+ dir[0];
            int nc = j + dir[1];

            result = ( result + solve(m, n, maxMove-1, nr, nc)) % M;
        }
        return dp[i][j][maxMove] = result;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};