#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> all;

    void gen(int i, int m, vector<int>& pat) {
        if (i == m) {
            all.push_back(pat);
            return;
        }
        for (int c = 0; c < 3; ++c) {
            if (i == 0 || pat[i - 1] != c) {
                pat.push_back(c);
                gen(i + 1, m, pat);
                pat.pop_back();
            }
        }
    }

    bool valid(const vector<int>& a, const vector<int>& b, int m) {
        for (int i = 0; i < m; ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        all.clear();
        vector<int> pat;
        gen(0, m, pat);

        int sz = all.size();
        if (sz == 0) return 0;

        vector<long long> dp(sz, 1);
        vector<vector<bool>> ok(sz, vector<bool>(sz));

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                ok[i][j] = valid(all[i], all[j], m);
            }
        }

        for (int col = 1; col < n; ++col) {
            vector<long long> next(sz, 0);
            for (int j = 0; j < sz; ++j) {
                for (int i = 0; i < sz; ++i) {
                    if (ok[i][j]) {
                        next[j] = (next[j] + dp[i]) % MOD;
                    }
                }
            }
            dp = next;
        }

        long long ans = 0;
        for (int i = 0; i < sz; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        return (int)ans;
    }
};
