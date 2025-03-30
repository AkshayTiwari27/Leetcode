class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int>result;
        int mini = INT_MAX;
        for(int i = 0; i<cost.size(); i++){
            mini = min(cost[i], mini);
            result.push_back(mini);
        }
        return result;
    }
};