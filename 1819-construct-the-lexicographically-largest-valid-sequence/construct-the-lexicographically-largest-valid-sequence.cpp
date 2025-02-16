class Solution {
public:
    // Global result vector and a boolean array to track used numbers.
    vector<int> res;
    vector<bool> used;
    int n;
    
    // Backtracking function to try placing numbers starting from position 'pos'
    bool dfs(int pos) {
        // Base case: if pos reaches the end of the sequence, a solution is found.
        if (pos == res.size()) return true;
        
        // If current position is already filled, skip to the next.
        if (res[pos] != 0) return dfs(pos + 1);
        
        // Try placing numbers in descending order from n to 1.
        for (int num = n; num >= 1; num--) {
            // Skip if this number is already used.
            if (used[num]) continue;
            
            if (num == 1) {
                // Place 1, which should occur only once.
                res[pos] = 1;
                used[1] = true;
                if (dfs(pos + 1)) return true;
                // Backtracking
                res[pos] = 0;
                used[1] = false;
            } else {
                // For numbers > 1, we need to place two occurrences with a gap of 'num'.
                if (pos + num < res.size() && res[pos + num] == 0) {
                    // Place the two occurrences.
                    res[pos] = num;
                    res[pos + num] = num;
                    used[num] = true;
                    if (dfs(pos + 1)) return true;
                    // Backtracking: remove the placements
                    res[pos] = 0;
                    res[pos + num] = 0;
                    used[num] = false;
                }
            }
        }
        // No valid configuration found from this state.
        return false;
    }
    
    vector<int> constructDistancedSequence(int n_) {
        n = n_;
        int size = 2 * n - 1;
        res.assign(size, 0);
        used.assign(n + 1, false);
        dfs(0);
        return res;
    }
};
