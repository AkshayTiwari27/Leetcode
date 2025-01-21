class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRow=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRow=0;
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            firstRow-=grid[0][i];
            long long robot=max(firstRow,secondRow);
            ans=min(ans,robot);
            secondRow+=grid[1][i];
        }

        return ans;
    }
};