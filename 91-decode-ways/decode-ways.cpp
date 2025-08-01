class Solution {
public:
    int dp[101];
    int solve(int i, string &s){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int result = solve(i+1, s);
        if(i+1< s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
        result += solve(i+2, s);

        return dp[i] = result;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};