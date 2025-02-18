class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int prefix_sum = 0;
        int remainder = 0;
        int total = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            remainder = prefix_sum % k;
            if(remainder < 0) remainder += k;
            if(mp.count(remainder)) total += mp[remainder];
            mp[remainder]++;
        }

        return total;
    }
};