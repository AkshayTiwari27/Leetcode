class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int prev=s[0];
        int count=1;
        bool ans=false;
        for(int i = 1; i < s.size(); i++){
            if(s[i]==prev) count++;
            else{
                if(count == k) return true;
                count = 1;
                prev = s[i];
            }
        }

        return count == k;
    }
};