class Solution {
public:
    bool check(int src, int col, vector<vector<int>>& graph, vector<int>&color){
        color[src] = col;

        for(auto& v: graph[src]){
            if(color[v] == -1){
                if(!check(v, !col, graph, color)) return false;
            }
            else if(color[v] == col) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, -1);

        for(int i = 0; i<V; i++){
            if(color[i] == -1){
                if(!check(i, 0, graph, color)) return false;
            }
        }

        return true;
    }
};