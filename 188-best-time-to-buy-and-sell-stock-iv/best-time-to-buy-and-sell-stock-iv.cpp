class Solution {
public:
    int dp[1001][201];
    int solve(int i, int trans_no, vector<int>&prices, int k){
        if(i == prices.size() || trans_no == 2 * k) return 0;

        if(dp[i][trans_no] != -1) return dp[i][trans_no];
        int profit = 0;
        if(trans_no %2 == 0) profit = max(-prices[i] + solve(i+1, trans_no+1, prices, k), solve(i+1, trans_no, prices, k));
        else profit = max(prices[i] + solve(i+1, trans_no+1, prices, k), solve(i+1, trans_no, prices, k));

        return dp[i][trans_no] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices, k);
    }
};