class Solution {
public:
    int count;
    void solve(vector<int>&used){
        count++;
        for(int i = 0; i < 26; i++){
            if(used[i] == 0) continue;

            used[i]--;

            solve(used);

            used[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        count = 0;
        vector<int>v(26,0);

        for(auto& ch:tiles){
            v[ch - 'A']++;
        }
        solve(v);

        return count-1;
    }
};