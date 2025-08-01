class Solution {
public:
    int dp[1001];
    int solve(int i, vector<int>&cost){
        int n = cost.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        int one = cost[i] + solve(i+1, cost);
        int two = cost[i] + solve(i+2, cost);

        return dp[i] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost), solve(1, cost));
    }
};