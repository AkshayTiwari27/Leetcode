class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1),right(n,1);

        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        for(int j=n-2;j>=0;j--){
            right[j]=right[j+1]*nums[j+1];
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }

        return ans;
    }
};