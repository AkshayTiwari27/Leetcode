class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n+1, vector<int>(((2*k) + 1), 0));

        for(int i = n-1; i>= 0; i--){
            for(int trans_no = 0; trans_no < 2*k; trans_no++){
                int profit = 0;
                if(trans_no % 2 == 0) profit = max(-prices[i] + dp[i+1][trans_no +1], dp[i+1][trans_no]);
                else profit = max(prices[i] + dp[i+1][trans_no +1], dp[i+1][trans_no]);
                dp[i][trans_no] = profit;
            }
        }

        return dp[0][0];
    }
};