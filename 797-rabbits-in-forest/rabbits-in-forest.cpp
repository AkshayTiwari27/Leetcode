class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int total = 0;
        unordered_map<int,int>mp;
        for(auto &x : answers){
            mp[x]++;
        }

        for(auto &it: mp){
            int x = it.first;
            int count = it.second;
            int group = ceil((double)count/(x+1));
            total += group * (x+1);
        }

        return total;
    }
};