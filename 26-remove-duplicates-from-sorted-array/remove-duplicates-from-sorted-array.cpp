class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(i < nums.size()){
            if(nums[i] == nums[j]) i++;
            else{
                j++;
                nums[j] = nums[i++]; 
            }
        }
        int k = j+1;
        return k;
    }
};