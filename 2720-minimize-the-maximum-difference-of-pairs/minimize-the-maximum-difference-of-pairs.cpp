class Solution {
public:
    bool find(vector<int>&nums, int mid, int p){
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            if(nums[i+1] - nums[i] <= mid){
                count++;
                i++;
                if(count == p) return true;
            }
        }
        return count == p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[n-1] - nums[0];
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(find(nums, mid, p)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        return ans;
    }
};