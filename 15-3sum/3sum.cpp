class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            int j = i+1; 
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum<0) j++;
                else k--;
            }
        }

        vector<vector<int>>ans;
        for(auto& v: st){
            ans.push_back(v);
        }

        return ans;
    }
};