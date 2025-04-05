class Solution {
public:
    int solve(vector<int>& nums, int i, int result){
        if(i == nums.size()) return result;

        int include = solve(nums, i+1, nums[i]^result);
        int exclude = solve(nums, i+1, result);
        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};