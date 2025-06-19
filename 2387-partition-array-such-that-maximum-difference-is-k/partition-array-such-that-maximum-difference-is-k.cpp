class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int count = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] - mini > k){
                count++;
                mini = nums[i];
            }
        }

        return count;
    }
};