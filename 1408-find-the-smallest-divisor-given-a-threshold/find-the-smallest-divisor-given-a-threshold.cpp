class Solution {
public:
    bool isPossible(int divisor,vector<int>&nums,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)divisor);
        }
        if(sum<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(mid,nums,threshold)) hi=mid-1;
            else lo=mid+1;
        }

        return lo;
    }
};