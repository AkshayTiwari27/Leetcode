class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<long, long>mp;
        mp[0] = 1;
        long long sum = 0;
        long long result = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] % m == k) sum += 1;
            long long r1 = sum % m;
            long long r2 = (r1 - k + m)%m;
            result += mp[r2];
            mp[r1]++;
        }
        return result;

    }
};