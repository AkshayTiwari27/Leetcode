struct State {
    long long time;
    int r, c;
    int next_move_cost_idx;

    bool operator>(const State& other) const {
        if (time != other.time) {
            return time > other.time;
        }
        if (r != other.r) {
            return r > other.r;
        }
        if (c != other.c) {
            return c > other.c;
        }
        return next_move_cost_idx > other.next_move_cost_idx;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, numeric_limits<long long>::max())));

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0][0] = 0LL;
        pq.push({0LL, 0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        long long move_costs_arr[] = {1, 2};

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            long long current_arrival_time = current.time;
            int r = current.r;
            int c = current.c;
            int current_next_move_idx = current.next_move_cost_idx;

            if (current_arrival_time > dist[r][c][current_next_move_idx]) {
                continue;
            }

            long long actual_move_duration_from_rc = move_costs_arr[current_next_move_idx];
            int next_next_move_idx_for_neighbor = 1 - current_next_move_idx;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    long long earliest_departure_allowed_by_target = static_cast<long long>(moveTime[nr][nc]);
                    long long departure_time_from_rc = max(current_arrival_time, earliest_departure_allowed_by_target);
                    
                    long long arrival_time_at_nr_nc = departure_time_from_rc + actual_move_duration_from_rc;

                    if (arrival_time_at_nr_nc < dist[nr][nc][next_next_move_idx_for_neighbor]) {
                        dist[nr][nc][next_next_move_idx_for_neighbor] = arrival_time_at_nr_nc;
                        pq.push({arrival_time_at_nr_nc, nr, nc, next_next_move_idx_for_neighbor});
                    }
                }
            }
        }

        long long result = min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);

        return result == numeric_limits<long long>::max() ? -1 : result;
    }
};
