class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> mp;
        for(int i = 0; i<s.length(); i++){
            mp[s[i] - 'a'] =i;
        }
        int start = 0;
        int end = 0;
        vector<int>result;
        for(int i = 0; i<s.length(); i++){
            end = max(mp[s[i] - 'a'], end);
            if(i == end){
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};