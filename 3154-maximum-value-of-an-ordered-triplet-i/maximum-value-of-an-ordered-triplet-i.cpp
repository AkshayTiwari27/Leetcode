class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix_max(n, 0);
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i-1], (long long)nums[i]);
        }
        
        vector<long long> suffix_max(n, 0);
        suffix_max[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i+1], (long long)nums[i]);
        }
        
        long long max_value = LLONG_MIN;
        for (int j = 1; j <= n-2; j++) {
            long long temp = (prefix_max[j-1] - nums[j]) * suffix_max[j+1];
            max_value = max(max_value, temp);
        }
        
        return max(0LL, max_value);
    }
};