class Solution {
public:
    int dp[101];
    int solve(string &s, int n, int i){
        if(i == n) return dp[i] = 1;
        if(s[i] == '0') return dp[i] = 0;

        if(dp[i] != -1) return dp[i];
        int result = solve(s, n, i + 1);
        if(i + 1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')){
                result += solve(s, n, i+2);
            }
        }

        return dp[i] = result;
    }
    int numDecodings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, n, 0);
    }
};