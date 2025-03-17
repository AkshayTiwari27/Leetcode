class Solution {
public:
    int n;
    int dp[366];
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i>= 0; i--){
            int cost1 = costs[0] + dp[i + 1];

            int j = i;
            while(j < n && days[j] < days[i] + 7){
                j++;
            }
            int cost7 = costs[1] + dp[j];

            j = i;
            while(j < n && days[j] < days[i] + 30){
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};