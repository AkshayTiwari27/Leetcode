class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int repeat = 0;
        for(int i = 1; i<n; i++){
            if(word[i] == word[i-1]) repeat++;
        }


        return repeat + 1;
    }
};