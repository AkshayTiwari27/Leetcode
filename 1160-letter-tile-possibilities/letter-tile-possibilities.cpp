class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char tile : tiles) {
            count[tile]++;
        }

        return backtrack(count);
    }

private:
    int backtrack(unordered_map<char, int>& count) {
        int result = 0;

        for (auto& entry : count) {
            if (entry.second > 0) {
                result++;
                entry.second--; 
                result += backtrack(count); 
                entry.second++; 
            }
        }

        return result;
    }
};
