class Solution {
public:
    int maxDiff(int num) {
        string s1 = to_string(num);
        string s2 = s1;

        // Maximize
        int idx = s1.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = s1[idx];
            replace(s1.begin(), s1.end(), ch, '9');
        }

        // Minimize
        if (s2[0] != '1') {
            char ch = s2[0];
            replace(s2.begin(), s2.end(), ch, '1');
        } else {
            for (int i = 1; i < s2.length(); i++) {
                if (s2[i] != '0' && s2[i] != s2[0]) {
                    char ch = s2[i];
                    replace(s2.begin(), s2.end(), ch, '0');
                    break;
                }
            }
        }

        return stoi(s1) - stoi(s2);
    }
};