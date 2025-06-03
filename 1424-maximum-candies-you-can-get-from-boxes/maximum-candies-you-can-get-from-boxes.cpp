class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>&visited, unordered_set<int>&found){
        if(visited.count(box)) return 0;
        if(status[box] == 0){
            found.insert(box);
            return 0;
        }
        visited.insert(box);
        int candy = candies[box];

        for(auto &num: containedBoxes[box]){
            candy += dfs(num, status, candies, keys, containedBoxes, visited, found);
        }
        for(auto &num: keys[box]){
            status[num] = 1;
            if(found.count(num)){
                candy += dfs(num, status, candies, keys, containedBoxes, visited, found);
            }
        }

        return candy;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candy = 0;
        unordered_set<int>found;
        unordered_set<int>visited;
        for(auto &num: initialBoxes){
            candy += dfs(num, status, candies, keys, containedBoxes, visited, found);
        }

        return candy;
    }
};