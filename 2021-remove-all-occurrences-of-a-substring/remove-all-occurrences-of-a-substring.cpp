class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for(int i=0; i<s.length();i++){
            result.push_back(s[i]);
            if(result.size() >= part.length() && result.substr(result.length() - part.length()) == part){
                result.erase(result.length() - part.length(), part.length());
            }
        }

        return result;
    }
};