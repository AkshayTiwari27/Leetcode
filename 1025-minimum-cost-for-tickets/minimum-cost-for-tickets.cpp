class Solution {
public:
    int dp[366];
    int solve(int i, vector<int>& days, vector<int>& costs){
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int cost1 = costs[0] + solve(i+1, days, costs);

        int j = i;
        int max_day = 7 + days[i];
        while(j<days.size() && days[j] < max_day) j++;
        int cost2 = costs[1] + solve(j, days, costs);

        
        j = i;
        max_day = 30 + days[i];
        while(j<days.size() && days[j] < max_day) j++;
        int cost3 = costs[2] + solve(j, days, costs);

        return dp[i] = min({cost1, cost2, cost3});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};