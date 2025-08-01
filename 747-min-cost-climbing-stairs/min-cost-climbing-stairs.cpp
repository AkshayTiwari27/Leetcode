class Solution {
public:
    int dp[1001];
    int solve(int i, vector<int>&cost, int n){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = cost[i] + solve(i + 1, cost, n);
        int not_take = cost[i] + solve(i+2, cost, n);

        return dp[i] = min(take, not_take);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost, n), solve(1, cost, n));
    }
};