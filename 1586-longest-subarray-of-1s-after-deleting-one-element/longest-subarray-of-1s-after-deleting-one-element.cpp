class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ones = 0;
        int maxi = 0;
        while(j < nums.size()){
            if(nums[j] == 0) ones++;

            while(ones > 1){
                if(nums[i] == 0) ones--;
                i++;
            }

            maxi = max(maxi, j-i);
            j++;
        }

        return maxi;
    }
};