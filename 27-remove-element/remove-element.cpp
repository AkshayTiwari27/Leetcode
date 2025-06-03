class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        int n = nums.size();
        while(j<n){
            if(nums[j] == val) j++;
            else{
                swap(nums[i++], nums[j++]);
            }
        }

        return i;
    }
};