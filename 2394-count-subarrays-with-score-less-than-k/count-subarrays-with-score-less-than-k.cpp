class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long result = 0;
        long long sum = 0;

        while(j<n){
            sum += nums[j];
            while(i <= j && sum *(j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            result += j - i + 1;
            j++;
        }

        return result;
    }
};