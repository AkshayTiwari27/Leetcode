class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int>mp1;
        unordered_map<int,int> mp2;

        for(auto& num: nums){
            mp2[num]++;
        }
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            int n1 = i + 1;
            int n2 = n - i - 1;
            if(mp1[nums[i]] * 2 > n1 && mp2[nums[i]] * 2 > n2) return i;
        }
        return -1;
    }
};