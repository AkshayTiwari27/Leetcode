class Solution {
public:
    vector<vector<int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(vector<vector<int>>& image, int i, int j, int color, int original){
        int m = image.size();
        int n = image[0].size();
        image[i][j] = color;

        for(auto& dir:directions){
            int row = dir[0] + i;
            int col = dir[1] + j;
            if(row >= 0 && row < m && col >= 0 && col < n && image[row][col] == original && image[row][col]!= color){
                image[i][j] = color;
                dfs(image, row, col, color, original);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int original = image[sr][sc];
        dfs(image,sr, sc, color, original);

        return image;
    }
};