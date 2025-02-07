class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>colcount;
        vector<int>result;
        for(auto q:queries){
            int ball=q[0];
            int color=q[1];
            if(mp.count(ball)){
                int prev=mp[ball];
                colcount[prev]--;
                if(colcount[prev]==0) colcount.erase(prev);
            }
            mp[ball]=color;
            colcount[color]++;
            result.push_back(colcount.size());
        }

        return result;
    }
};