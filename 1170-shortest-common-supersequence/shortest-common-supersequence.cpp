class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (str1[i] == str2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        
        int i = 0, j = 0;
        string lcs;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                lcs.push_back(str1[i]);
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }
        
        i = 0, j = 0;
        string scs;
        for (char c : lcs) {
            while (i < n && str1[i] != c) {
                scs.push_back(str1[i]);
                i++;
            }
            while (j < m && str2[j] != c) {
                scs.push_back(str2[j]);
                j++;
            }
            scs.push_back(c);
            i++;
            j++;
        }
        
        scs.append(str1.substr(i));
        scs.append(str2.substr(j));
        
        return scs;
    }
};