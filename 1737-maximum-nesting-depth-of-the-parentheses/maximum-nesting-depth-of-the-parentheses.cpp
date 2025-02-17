class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int brackets = 0;
        for(auto & ch: s){
            if(ch == '(') brackets++;
            else if(ch == ')') brackets--;

            result = max(result, brackets);
        }

        return result;
    }
};