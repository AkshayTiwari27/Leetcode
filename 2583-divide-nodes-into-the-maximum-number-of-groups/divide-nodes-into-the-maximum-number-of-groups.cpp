class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1);
        vector<vector<int>> components;
        unordered_set<int> visited;
        
        for (int i = 1; i <= n; ++i) {
            if (visited.count(i)) continue; 
            queue<int> q;
            vector<int> component;
            q.push(i);
            color[i] = 0;
            visited.insert(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component.push_back(node);
                
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = color[node] ^ 1; 
                        q.push(neighbor);
                        visited.insert(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return -1; 
                    }
                }
            }
            components.push_back(component);
        }

        auto bfs_max_depth = [&](int start) {
            queue<int> q;
            unordered_map<int, int> depth;
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        int totalGroups = 0;
        for (const auto& comp : components) {
            int maxGroups = 0;
            for (int node : comp) {
                maxGroups = max(maxGroups, bfs_max_depth(node));
            }
            totalGroups += maxGroups;
        }

        return totalGroups;
    }
};
