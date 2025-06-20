class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix=0;
        int maxi=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            maxi=max(maxi,prefix);

            if(prefix<0) prefix=0;
        }

        return maxi;
    }
};