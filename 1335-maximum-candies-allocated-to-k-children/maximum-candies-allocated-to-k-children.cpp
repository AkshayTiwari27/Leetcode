class Solution {
public:
    bool isPossible(int mid, vector<int>& candies, long long k){
        long long count = 0;
        for(int i = 0; i < candies.size(); i++){
            count += candies[i]/mid;
            if(count >= k) return true;
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1;
        int hi = *max_element(candies.begin(),candies.end());
        long long count = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(mid, candies, k)){
                count = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return count;
    }
};