class Solution {
public:
    
    int climbStairs(int n) {
        int prev1 = 1;
        int prev = 1;
        if(n ==1) return 1;
        int curr = prev + prev1;
        for(int i = 2; i<=n; i++){
            curr = prev + prev1;
            prev1= prev;
            prev = curr;
        }
        return curr;
    }
};