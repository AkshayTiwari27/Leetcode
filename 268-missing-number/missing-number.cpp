class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum1 = n*(n+1)/2;

        int sum2 = accumulate(nums.begin(), nums.end(), 0);
        ans = (sum1 - sum2);
        return ans;
    }
};