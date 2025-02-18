class Solution {
public:
    bool matches(string &num, string& pattern){
        for(int i = 0; i < pattern.size(); i++){
            if((pattern[i] == 'I' && num[i] >num[i + 1]) || (pattern[i] == 'D' && num[i] < num[i + 1])) return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        string num;
        int n = pattern.size();
        for(int i = 1; i <= n + 1; i++){
            num.push_back(i + '0');
        }

        while(!matches(num, pattern)){
            next_permutation(num.begin(), num.end());
        }

        return num;
    }
};