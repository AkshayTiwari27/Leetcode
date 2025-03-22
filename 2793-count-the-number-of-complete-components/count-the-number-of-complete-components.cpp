class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj, int i, vector<bool>&visited, int &v, int &e){
        visited[i] = true;
        v++;
        e += adj[i].size();
        for(auto& node: adj[i]){
            if(!visited[node]){
                dfs(adj, node, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        int result = 0;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == true) continue;
            int v = 0;
            int e = 0;
            dfs(adj, i, visited, v, e);

            if(v * (v - 1) == e) result++;
        }

        return result;
    }
};