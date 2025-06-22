class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of all characters
        for (char c : s) {
            freq[c]++;
        }

        // Convert map to vector of pairs {char, freq}
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build the result string
        string result;
        for (auto &[ch, count] : freqVec) {
            result += string(count, ch);
        }

        return result;
    }
};
