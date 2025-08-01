class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[0];
        int prev = cost[1];
        int curr = min(prev1, prev);

        for(int i = 2; i<n; i++){
            curr = cost[i] + min(prev, prev1);
            prev1 = prev;
            prev = curr;
        }

        return min(prev, prev1);
    }
};