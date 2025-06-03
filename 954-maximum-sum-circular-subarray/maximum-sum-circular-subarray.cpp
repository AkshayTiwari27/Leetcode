class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int prefix = 0;           // for max subarray sum
        int maxi = INT_MIN;
        
        int mini = INT_MAX;       // for min subarray sum
        int prefix_min = 0;

        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];

            // For maximum subarray (Kadane's)
            prefix += nums[i];
            maxi = max(maxi, prefix);
            if(prefix < 0) prefix = 0;

            // For minimum subarray (inverted Kadane's)
            prefix_min += nums[i];
            mini = min(mini, prefix_min);
            if(prefix_min > 0) prefix_min = 0;
        }

        // If all elements are negative, return the max (non-circular) subarray
        if(maxi < 0) return maxi;

        // Return max of non-circular or circular case
        return max(maxi, totalSum - mini);
    }
};
