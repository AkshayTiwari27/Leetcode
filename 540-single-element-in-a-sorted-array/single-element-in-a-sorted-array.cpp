class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            bool isEven=(right-mid)%2==0;

            if(nums[mid]==nums[mid+1]){
                if(isEven){
                    left=mid+2;
                }
                else right=mid-1;
            }
            else{
                if(isEven){
                    right=mid;
                }
                else left=mid+1;
            }
        }

        return nums[right];
    }
};