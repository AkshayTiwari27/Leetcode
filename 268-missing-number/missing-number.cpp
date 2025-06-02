class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        ans = ans^n;
        for(int i = 0; i<n; i++){
            ans^= nums[i] ^ i;
        }

        return ans;
    }
};