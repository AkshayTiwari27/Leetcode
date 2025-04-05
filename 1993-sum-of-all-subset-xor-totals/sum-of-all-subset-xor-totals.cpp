class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i< nums.size(); i++){
            result|= nums[i];
        }

        return result << (nums.size()-1);
    }
};