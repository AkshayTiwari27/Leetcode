class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0, count = 0, start = 0, end = 0;
        unordered_map<int, int>mp;

        while(end < n){
            mp[nums[end]]++;
            if(mp[nums[end]] == 1) count++;
            while(count == k){
                total += n - end;
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) count--;
                start++;
            }
            end++;
        }
        mp.clear();
        k++;
        count = 0, start = 0, end = 0;
        while(end < n){
            mp[nums[end]]++;
            if(mp[nums[end]] == 1) count++;
            while(count == k){
                total -= n - end;
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) count--;
                start++;
            }
            end++;
        }

        return total;
    }
};