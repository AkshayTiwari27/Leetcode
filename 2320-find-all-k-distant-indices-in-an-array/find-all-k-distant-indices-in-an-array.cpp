class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                for(int j = max(0, i - k); j <= min(i + k, n-1); j++){
                    st.insert(j);
                }
            }
        }

        vector<int>ans(st.begin(), st.end());
        return ans;
    }
};