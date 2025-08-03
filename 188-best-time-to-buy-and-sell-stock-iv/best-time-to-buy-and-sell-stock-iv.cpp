class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int>curr(2*k + 1, 0), ahead(2*k + 1, 0);
        for(int i = n-1; i>= 0; i--){
            for(int trans_no = 0; trans_no < 2*k; trans_no++){
                int profit = 0;
                if(trans_no % 2 == 0) profit = max(-prices[i] + ahead[trans_no +1], ahead[trans_no]);
                else profit = max(prices[i] + ahead[trans_no +1], ahead[trans_no]);
                curr[trans_no] = profit;
            }
            ahead = curr;
        }

        return ahead[0];
    }
};