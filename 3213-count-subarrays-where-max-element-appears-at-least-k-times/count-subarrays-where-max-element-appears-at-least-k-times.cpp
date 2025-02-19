class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start = 0, end = 0, count = 0;
        long long total = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        while(end < nums.size()){
            if(nums[end] == maxi) count++;

            while(count == k){
                total += nums.size() - end;
                if(nums[start] == maxi) count--;
                start++;
            }
            end++;
        }

        return total;
    }
};