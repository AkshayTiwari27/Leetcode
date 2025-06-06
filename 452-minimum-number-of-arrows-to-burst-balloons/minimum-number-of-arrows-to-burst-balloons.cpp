class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());               // Sort balloons by start point
        int lastpoint = p[0][1];               // Track where the current arrow ends
        int ans = 1;                           // At least one arrow needed

        for(auto point : p) {
            if(point[0] > lastpoint) {        // New balloon starts after last arrow range
                ans++;
                lastpoint = point[1];         // New arrow needed
            }
            lastpoint = min(point[1], lastpoint); // Update overlap range
        }
        return ans;
    }
};