class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        int equivalentPairCount = 0;

        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            int min_val = std::min(a, b);
            int max_val = std::max(a, b);
            int canonicalKey = min_val * 10 + max_val;
            equivalentPairCount += freq[canonicalKey];
            freq[canonicalKey]++;
        }

        return equivalentPairCount;
    }
};