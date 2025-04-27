class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        vector<int>v(3);
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            v.clear();
            for(int j=i;j<=i+2;j++){
                v.push_back(nums[j]);
            }
            if(2*(v[0]+v[2])==v[1]) ans++;
        }

        return ans;
    }
};