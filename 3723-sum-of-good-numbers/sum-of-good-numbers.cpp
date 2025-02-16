class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool leftGood = (i - k < 0) || (nums[i] > nums[i - k]);
            bool rightGood = (i + k >= n) || (nums[i] > nums[i + k]);
            if (leftGood && rightGood) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
};
