class Solution {
public:
    string clearDigits(string s) {
        string result;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                if(!result.empty()) result.pop_back();
            }
            else result+=s[i];
        }

        return result;
    }
};