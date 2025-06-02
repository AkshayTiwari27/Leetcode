class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i = 0; i<n; i++){
            v.push_back({nums[i], i});
        }

        int lo = 0;
        int hi = n-1;
        sort(v.begin(), v.end());
        while(lo<= hi){
            int sum = v[lo].first + v[hi].first;
            if(sum == target) return {v[lo].second, v[hi].second};
            else if(sum < target) lo++;
            else hi--;
        }

        return {-1,-1};
    }
};