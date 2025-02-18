class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        unordered_map<long long int, long long int>mp;
        mp[0] = 1;
        long long int prefix_sum = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            if(mp.count(prefix_sum - k)) {
                total += mp[prefix_sum - k];
            }
            mp[prefix_sum]++;
        }

        return total;
    }
};