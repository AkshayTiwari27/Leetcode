class Solution {
public:
    bool isPossible(long long time, vector<int>& ranks, int cars){
        long long total = 0;
        for(int i = 0; i < ranks.size(); i++){
            total += sqrt(time/ranks[i]);
        }
        return total >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 1;
        long long rank = *max_element(ranks.begin(), ranks.end());
        long long hi = rank * cars * cars;
        long long result = 0;
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            if(isPossible(mid, ranks, cars)){
                result = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return result;
    }
};