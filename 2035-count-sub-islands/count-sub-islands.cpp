class Solution {
public:
    vector<vector<int>>directions = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        int m = grid2.size();
        int n = grid2[0].size();
        
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1)
            return true;  
        
        bool isSub = (grid1[i][j] == 1);  
        
        grid2[i][j] = -1;  
        
        for(auto dir : directions){
            int row = i + dir[0];
            int col = j + dir[1];
            if (!dfs(grid1, grid2, row, col))
                isSub = false;  
        }

        return isSub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && dfs(grid1, grid2, i, j))
                    count++;
            }
        }
        return count;
    }
};
