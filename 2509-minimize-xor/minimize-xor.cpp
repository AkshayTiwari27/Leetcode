class Solution {
public:
    bool setbits(int &x, int bit) {
        if (bit >= 0 && bit < 32) {
            x |= (1 << bit);
            return true;
        }
        return false;
    }

    bool issetbits(int &x, int bit) {
        if (bit >= 0 && bit < 32) {
            return x & (1 << bit);
        }
        return false;
    }

    bool unsetbits(int &x, int bit) {
        if (bit >= 0 && bit < 32) {
            x &= ~(1 << bit);
            return true;
        }
        return false;
    }

    int minimizeXor(int num1, int num2) {
        int x = 0;
        int req_setbits = __builtin_popcount(num2);
        
        for(int bit=31;bit>=0 && req_setbits>0;bit--){
            if(issetbits(num1,bit)){
                setbits(x,bit);
                req_setbits--;
            }
        }

        for(int bit=0;bit<32 && req_setbits>0;bit++){
            if(!issetbits(x,bit)){
                setbits(x,bit);
                req_setbits--;
            }
        }

        return x;
    }
};
