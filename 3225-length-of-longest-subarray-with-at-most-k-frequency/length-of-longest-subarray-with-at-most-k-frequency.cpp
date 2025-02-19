class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0, length = INT_MIN, end = 0;
        int n = nums.size();
        unordered_map<int, int>mp;

        while(end < n){
            mp[nums[end]]++;
            while(mp[nums[end]] > k){
                mp[nums[start]]--;
                start++;
            }
            length = max(length, end - start + 1);
            end++;
        }
        return length;
    }
};