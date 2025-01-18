class Solution {
public:
    bool isPossible(int capacity,vector<int>&weights,int days){
        int day=1, load=0;

        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=capacity) load+=weights[i];
            else{
                day+=1;
                load=weights[i];
            }
        } 

        if(day<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(mid,weights,days)) hi=mid-1;
            else lo=mid+1;
        }

        return lo;
    }
};