class Solution {
public:
    int dp[30001][2];
    int solve(int i, vector<int>&prices, int buy){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solve(i+1, prices, 0), solve(i+1, prices, 1));
        }
        else profit = max(prices[i] + solve(i+1, prices, 1), solve(i+1, prices, 0));

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, 1);
    }
};