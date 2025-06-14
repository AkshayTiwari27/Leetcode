class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, i = 0;
        while (n) {
            ans |= (n & 1) << (31 - i++);
            n >>= 1;
        }       
        return ans;
    }
};
