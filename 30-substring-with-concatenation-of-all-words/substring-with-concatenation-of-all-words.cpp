class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowSize = wordLen * wordCount;

        if (s.size() < windowSize) return result;

        // Step 1: Build the frequency map of the words
        unordered_map<string, int> targetFreq;
        for (string& word : words) {
            targetFreq[word]++;
        }

        // Step 2: Try all starting positions within the word length
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> windowFreq;
            int left = i, right = i, count = 0;

            while (right + wordLen <= s.size()) {
                // Step 3: Expand window
                string word = s.substr(right, wordLen);
                right += wordLen;

                // If it's a valid word
                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    count++;

                    // Step 4: Shrink window if word appears too many times
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Step 5: If window has all words, record result
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window if word not in target
                    windowFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
