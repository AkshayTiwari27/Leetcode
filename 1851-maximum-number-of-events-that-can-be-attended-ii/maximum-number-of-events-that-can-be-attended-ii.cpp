class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, events, k, dp);
    }

    int solve(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if(k == 0 || i == events.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int next = findNext(events, i);

        int take = events[i][2] + solve(next, events, k - 1, dp);
        int not_take = solve(i + 1, events, k, dp);

        return dp[i][k] = max(take, not_take);
    }

    int findNext(vector<vector<int>>& events, int i) {
        int low = i + 1, high = events.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if(events[mid][0] > events[i][1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
