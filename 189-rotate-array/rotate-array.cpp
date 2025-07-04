class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        k %= n;  

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[(i + k) % n] = nums[i];
        }

        nums = ans;
    }
};
