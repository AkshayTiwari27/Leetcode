class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i<= high; i++){
            string s = to_string(i);
            int l = s.length();
            if((l%2) != 0) continue;

            int left = 0;
            int right = 0;
            for(int i = 0; i<l/2; i++){
                left += s[i] - '0';
            }
            for(int j = l/2; j<l; j++){
                right += s[j]- '0';
            }
            if(left == right) count++;
        }

        return count;
    }
};