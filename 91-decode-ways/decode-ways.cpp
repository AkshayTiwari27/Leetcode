class Solution {
public:
    int dp[101];
    int solve(int i, string &s, int n){
        if(i==n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int result = solve(i+1, s, n);
        if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
        result += solve(i + 2, s, n);


        return dp[i] = result;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return solve(0, s, n);
    }
};