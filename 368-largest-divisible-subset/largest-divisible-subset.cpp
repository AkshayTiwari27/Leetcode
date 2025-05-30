class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>t(n, 1);
        vector<int>prev(n,-1);
        int last_index = 0;
        int maxi = 1;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(t[i] < t[j] + 1){
                        t[i] = t[j] + 1;
                        prev[i] = j;
                    }
                }
                if(t[i] >maxi){
                    maxi = t[i];
                    last_index = i;
                }
            }
        }

        vector<int>result;
        while(last_index != -1){
            result.push_back(nums[last_index]);
            last_index = prev[last_index];
        }

        return result;
    }
};