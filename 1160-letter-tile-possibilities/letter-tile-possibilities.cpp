class Solution {
public:
    void solve(string tiles, vector<bool>&used, unordered_set<string>&result, string &curr){
        result.insert(curr);
        for(int i = 0; i < tiles.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string>result;
        vector<bool>used(n,false);
        string curr = "";
        solve(tiles, used, result, curr);
        return result.size()-1;
    }
};