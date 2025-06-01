class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int n = nums.size();
        int count = 0;
        for(int i =1 ; i<nums.size(); i++){
            if(nums[i] < nums[(i-1)]) count++;
        }
        if(nums[n-1] > nums[0]) count++;

        return count <= 1;
    }
};