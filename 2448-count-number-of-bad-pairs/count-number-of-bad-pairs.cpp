class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++){
            result += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }

        return result;
    }
};