class Solution {
public:
    bool canZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); 

        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        int current_decrement = 0;
        for (int i = 0; i < n; i++) {
            current_decrement += diff[i];
            if (current_decrement < nums[i]) return false; 
        }

        return true; 
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size(), ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canZeroArray(nums, queries, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};
