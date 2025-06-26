class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int p2 = 1;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '0') count++;
            else {
                if(p2 <= k){
                    k -= p2;
                    count++;
                }
            }

            if(p2 <= k) p2 *= 2;
        }

        return count;
    }
};