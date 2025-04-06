class Solution {
public:
    vector<vector<int>>directions = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>>& land, int i, int j, int& r, int& c){
        land[i][j] = 0;
        r = max(r, i);
        c = max(c, j);
        int m = land.size();
        int n = land[0].size();

        for(auto &dir : directions){
            int row = dir[0] + i;
            int col = dir[1] + j;

            if(row >= 0 && row < m && col >= 0 && col < n && land[row][col] == 1){
                dfs(land, row, col, r, c);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>result;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(land[i][j] == 1){
                    int r = -1;
                    int c = -1;
                    dfs(land, i, j, r, c);
                    result.push_back({i,j,r,c});
                }
            }
        }

        return result;
    }
};