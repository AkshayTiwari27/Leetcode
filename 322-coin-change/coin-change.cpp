class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>&dp){
        if(i==0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return INT_MAX-1;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int notTake = solve(coins, amount, i-1,dp);
        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + solve(coins, amount - coins[i], i, dp);
        }
        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int result = solve(coins, amount, n - 1, dp);
        return (result == INT_MAX - 1) ? -1 : result; 
    }
};