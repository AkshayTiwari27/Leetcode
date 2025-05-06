class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int newValue = nums[nums[i]] % n;
            nums[i] = nums[i] + n * newValue;
        }
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] / n;
        }
        return nums;
    }
};