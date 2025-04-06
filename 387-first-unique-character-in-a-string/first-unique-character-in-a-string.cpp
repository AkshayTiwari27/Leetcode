class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>mp;
        for(auto& ch:s){
            mp[ch - 'a']++;
        }

        for(int i = 0; i<s.length(); i++){
            if(mp[s[i] - 'a'] == 1) return i;
        }
        return -1;

    }
};