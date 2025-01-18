class Solution {
public:
    typedef long long LL;
    bool isPossible(int day,vector<int>&bloomDay,int m,int k){
        int count=0;
        int bouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) count++;
            else{
                bouquet+=count/k;
                count=0;
            }
        }
        bouquet+=count/k;
        if(bouquet>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long a=m* 1LL *k* 1LL;
        if(a>bloomDay.size()) return -1;
        int lo=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isPossible(mid,bloomDay,m,k)) hi=mid-1;
            else lo=mid+1;

        }

        return lo;
    }
};