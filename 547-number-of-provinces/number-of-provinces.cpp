class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<bool>&visited){
        visited[node] = true;
        for(auto &v : adj[node]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i!= j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool>visited(n, false);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(adj, i, visited);
            }
        }

        return count;
    }
};