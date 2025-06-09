class Solution {
public:
    // Count how many numbers are in [curr, next) that are ≤ n
    int count(long long curr, long long next, int n) {
        int count = 0;
        while (curr <= n) {
            count += min((long long)(n + 1), next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--; // Because we start from 1

        while (k > 0) {
            int counti = count(curr, curr + 1, n);
            if (counti <= k) {
                curr += 1;      // Move to next prefix
                k -= counti;
            } else {
                curr *= 10;     // Go deeper into current prefix
                k -= 1;
            }
        }

        return (int)curr;
    }
};
