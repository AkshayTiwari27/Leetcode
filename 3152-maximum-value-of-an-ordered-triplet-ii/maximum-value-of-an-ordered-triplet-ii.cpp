class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long dmax = 0;
        long long imax = 0;
        long long result = 0;
        for(int i = 0; i<nums.size(); i++){
            result = max(result, dmax* (long long)nums[i]);
            dmax = max(dmax, imax - (long long)nums[i]);
            imax = max(imax, (long long)nums[i]);
        }

        return result;
    }
};