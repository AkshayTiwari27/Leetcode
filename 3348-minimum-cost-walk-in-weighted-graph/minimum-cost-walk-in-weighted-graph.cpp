class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> component(n, -1);
        vector<int> minAndValue(n, INT_MAX);
        int compId = 0;
        
        for (int i = 0; i < n; i++) {
            if (component[i] != -1) continue; 
            
            queue<int> q;
            q.push(i);
            component[i] = compId;
            int minAnd = INT_MAX;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (auto& [neighbor, weight] : graph[node]) {
                    minAnd &= weight;
                    if (component[neighbor] == -1) {
                        component[neighbor] = compId;
                        q.push(neighbor);
                    }
                }
            }
            minAndValue[compId] = minAnd;
            compId++;
        }

        vector<int> result;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] == component[t]) {
                result.push_back(minAndValue[component[s]]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};