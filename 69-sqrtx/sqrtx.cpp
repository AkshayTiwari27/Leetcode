class Solution {
public:
    int mySqrt(int x) {
        long long lo=1;
        long long hi=x;
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(mid*mid<=x){
                lo=mid+1;
            }
            else hi=mid-1;
        }


        return hi;
    }
};