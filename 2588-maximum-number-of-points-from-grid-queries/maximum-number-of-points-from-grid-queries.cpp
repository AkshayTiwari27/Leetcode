class Solution {
public:
    vector<vector<int>>directions = {{-1, 0}, {0,-1}, {0,1}, {1, 0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        vector<pair<int,int>>q;
        for(int i = 0; i<Q; i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<int>result(Q);
        int points = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0], 0 , 0});
        visited[0][0] = true;

        for(int i = 0; i<Q; i++){
            int queryval = q[i].first;
            int idx = q[i].second;
            
            while(!pq.empty() && pq.top()[0] < queryval){
                int i__ = pq.top()[1];
                int j__ = pq.top()[2];
                pq.pop();
                points++;

                for(auto& dir: directions){
                    int i_ = i__ + dir[0];
                    int j_ = j__ + dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            
            result[idx] = points;
        }

        return result;
    }
};