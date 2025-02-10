class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        int j = 0;
        while(i < s.length()){
            if(isdigit(s[i])){
                j=max(j-1,0);
                i++;
            }
            else{
                s[j++] = s[i++];
            }
        }

        return s.substr(0,j);
    }
};