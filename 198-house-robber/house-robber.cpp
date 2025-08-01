class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0;
        int prev = nums[0];
        int curr = max(prev, prev1);

        for(int i =2; i<=n; i++){
            curr = max(nums[i-1] + prev1, prev);
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};