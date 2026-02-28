class Solution {
public:
    int concatenatedBinary(int n) {
        const int M = 1e9 + 7;
        long long result = 0;
        int digit = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0) digit++;  
            result = ((result << digit) % M + i) % M;
        }

        return (int)result;
    }
};