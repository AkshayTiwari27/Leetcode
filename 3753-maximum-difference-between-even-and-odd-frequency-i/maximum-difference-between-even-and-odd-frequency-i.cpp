class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        int maxi = 0;
        int mini = INT_MAX;
        bool evenExists = false;

        for (auto& [ch, freq] : mp) {
            if (freq % 2 != 0) {
                maxi = max(maxi, freq);
            } else {
                mini = min(mini, freq);
                evenExists = true;
            }
        }

        if (!evenExists) mini = 0;

        return maxi - mini;
    }
};
