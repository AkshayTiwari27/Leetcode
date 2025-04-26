using ll = long long;

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        int lastBad = -1;     
        int lastMin = -1;      
        int lastMax = -1;     
        
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastBad = i;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            ans += std::max(0, std::min(lastMin, lastMax) - lastBad);
        }
        
        return ans;
    }
};
