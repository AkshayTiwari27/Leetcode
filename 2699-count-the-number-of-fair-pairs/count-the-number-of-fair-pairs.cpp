class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            int idx = lower_bound(nums.begin() + i+1, nums.end(), lower - nums[i]) - nums.begin();
            int x = idx - i - 1;
            idx = upper_bound(nums.begin() + i+1, nums.end(), upper - nums[i]) - nums.begin();
            int y = idx - i - 1;

            count += y-x;
        }

        return count;
    }
};