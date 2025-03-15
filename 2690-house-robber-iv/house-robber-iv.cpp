class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid){
                count++;
                i++;
            }
        }

        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        int result = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(mid, nums, k)){
                result = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return result;
    }
};