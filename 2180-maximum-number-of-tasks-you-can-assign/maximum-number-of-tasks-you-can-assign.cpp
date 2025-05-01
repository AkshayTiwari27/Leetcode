bool can_complete(int k, int n, int m, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
    if (k == 0) {
        return true;
    }
    if (k > m) {
        return false;
    }

    multiset<int> available_workers;
    for (int i = 0; i < k; ++i) {
        available_workers.insert(workers[m - k + i]);
    }

    long long current_pills = pills;

    for (int i = k - 1; i >= 0; --i) {
        int current_task_strength = tasks[i];

        auto it_no_pill = available_workers.lower_bound(current_task_strength);

        if (it_no_pill != available_workers.end()) {
            available_workers.erase(it_no_pill);
        } else {
            if (current_pills <= 0) {
                return false;
            }

            long long required_strength_val = (long long)current_task_strength - strength;
            auto it_pill = available_workers.lower_bound((int)required_strength_val);

            if (it_pill != available_workers.end()) {
                available_workers.erase(it_pill);
                current_pills--;
            } else {
                return false;
            }
        }
    }

    return true;
}

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0;
        int high = min(n, m);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can_complete(mid, n, m, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
