class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<long long>> dist(n, vector<long long>(m, numeric_limits<long long>::max()));
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (time > dist[r][c]) continue;
            if (r == n - 1 && c == m - 1) return time;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    long long t = max(time, (long long)moveTime[nr][nc]) + 1;
                    if (t < dist[nr][nc]) {
                        dist[nr][nc] = t;
                        pq.push({t, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};