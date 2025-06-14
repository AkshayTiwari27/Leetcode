class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = false;
        }

        long n = abs((long)dividend);  // Cast to long before abs to avoid overflow
        long d = abs((long)divisor);   // Cast to long before abs
        long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += (1L << cnt);
            n -= (d << cnt);
        }

        if (quotient == (1L << 31) && sign) {
            return INT_MAX;
        }

        if (quotient == (1L << 31) && !sign) {
            return INT_MIN;
        }

        return sign ? quotient : -quotient;
    }
};
