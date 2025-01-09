class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-1;
        int result=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>mid){
                result=mid;
                right=mid-1;
            }
            else left=mid+1;
        }

        return result;
    }
};