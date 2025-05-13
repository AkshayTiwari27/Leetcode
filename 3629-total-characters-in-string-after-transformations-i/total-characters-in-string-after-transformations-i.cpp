class Solution {
public:
    long long M = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>mp(26,0);
        for(int i = 0; i<s.size();i++){
            mp[s[i]-'a']++;
        }

        for(int i = 0; i<t; i++){
            vector<int>temp(26,0);
            for(int i = 0; i<26;i++){
                char ch = i + 'a';
                int freq = mp[i];
                if(ch != 'z'){
                    temp[(ch + 1) -'a'] = (temp[(ch + 1) -'a'] +freq) %M;
                }else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) %M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) %M;
                }
            }

            mp = temp;
        }

        int sum = 0;
        for(int i = 0; i<26; i++){
            sum = (sum + mp[i]) % M;
        }
        return sum;
    }
};