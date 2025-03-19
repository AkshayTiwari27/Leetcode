class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 3;
        int total = 0;
        int n = nums.size();
        vector<bool>flip(n,false);
        int flipCount = 0;

        for(int i = 0; i < n; i++){
            if(i >= k && flip[i-k] == true) flipCount--;

            if(flipCount%2 == nums[i]){
                if(i + k > n) return -1;
                flipCount++;
                total++;
                flip[i] = true;
            }
        }

        return total;

    }
};