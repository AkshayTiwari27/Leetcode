class Solution {
public:
    int dp[100001][2][3];
    int solve(int i, int buy, vector<int>&prices, int cap){
        if(i == prices.size() || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        if(buy) profit = max(-prices[i] + solve(i+1, 0, prices, cap), solve(i+1, 1, prices, cap));
        else profit = max(prices[i] + solve(i+1, 1, prices, cap-1), solve(i+1, 0, prices, cap));

        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, prices, 2);
    }
};