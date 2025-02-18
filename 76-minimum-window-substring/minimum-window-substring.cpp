class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(auto &ch: t) mp[ch]++;
        int start = 0, end = 0, index = -1, ans = INT_MAX, total = t.size();
        while(end < s.size()){
            mp[s[end]]--;
            if(mp[s[end]] >= 0) total--;

            while(total==0 && start <= end){
                if(ans > end - start + 1){
                    ans = end - start + 1;
                    index = start;
                }
                mp[s[start]]++;
                if(mp[s[start]] > 0) total++;
                start++;
            }
            end++;
        }

        if(index == -1) return "";

        return s.substr(index, ans); 
    }
};