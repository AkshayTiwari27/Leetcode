class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>count(26,0);
        for(auto &ch : s){
            count[ch - 'a']++;
        }

        string first = "";
        char mid = 0;
        for(int i = 0; i<26; i++){
            if(count[i] > 0){
                first += string(count[i]/2, (char)(i + 'a'));
                if(count[i]%2 == 1) mid = (char)(i + 'a');
            }
        }

        string right = first;
        reverse(right.begin(), right.end());
        if(mid != 0) return first + mid + right;
        else return first + right;
    }
};