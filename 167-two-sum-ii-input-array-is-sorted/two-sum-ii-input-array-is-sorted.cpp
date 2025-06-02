class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            if(nums[lo] + nums[hi] == target) return {lo+1, hi+1};
            else if(nums[lo] + nums[hi] < target) lo++;
            else hi--;
        }

        return {-1, -1};
    }
};