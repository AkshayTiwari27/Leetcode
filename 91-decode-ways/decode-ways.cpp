class Solution {
public:
    int dp[101];
   
    int numDecodings(string s) {
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        dp[n] = 1;
        for(int i = n-1; i>= 0; i--){
            if(s[i] == '0') dp[i] = 0;
            else{
                int result = dp[i+1];
                if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
                result += dp[i+2];

                dp[i] = result;
            }
        }

        return dp[0];
        
    }
};