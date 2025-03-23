class Solution {
public:
    typedef pair<long long, int> p;
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto &edge: roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> result(n, LLONG_MAX);
        vector<int>pathcount(n, 0);
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0, 0});
        pathcount[0] = 1;
        result[0] = 0;

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &v : adj[currNode]){
                int neigh = v.first;
                long long roadTime = v.second;

                if(roadTime + currTime < result[neigh]){
                    result[neigh] = roadTime + currTime;
                    pathcount[neigh] = pathcount[currNode];
                    pq.push({result[neigh], neigh});
                }
                else if(roadTime + currTime == result[neigh]){
                    pathcount[neigh] = (pathcount[neigh] + pathcount[currNode])% MOD;
                }
            }
        }

        return pathcount[n-1];
    }
};