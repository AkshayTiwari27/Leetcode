class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>st(nums2.begin(),nums2.end());
        int ans=-1;

        for(int i=0;i<nums1.size();i++){
            if(st.find(nums1[i])!=st.end()){
                ans=nums1[i];
                break;
            }
        }

        return ans;
    }
};