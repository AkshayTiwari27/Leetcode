class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int node, vector<bool>&visited){
        visited[node] = true;
        for(auto &v : rooms[node]){
            if(!visited[v]){
                dfs(rooms, v, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms, 0, visited);
        for(int i = 0; i<visited.size(); i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};