class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int diff = 0;
        int updated = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]> updated){
                updated = nums[i];
            }
            else{
                diff = abs(nums[i] - updated) + 1; 
                updated = nums[i] + diff;
                count += diff;
            }
        }
        return count;
    }
};