class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(), v.end());
        int l = v.size();
        int target = v[l/2];
        int count = 0;
        for(int i = 0; i<v.size(); i++){
            if(target % x != v[i]%x) return -1;
            count += abs(target - v[i])/x;
        }
        return count;
    }
};