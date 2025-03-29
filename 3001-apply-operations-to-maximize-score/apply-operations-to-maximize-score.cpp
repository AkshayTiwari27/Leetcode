class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    long long pow_mod(long long a, long long b, long long MOD) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> prime_score(100001, 0);
        for (int p = 2; p <= 100000; p++) {
            if (prime_score[p] == 0) { // p is prime
                for (int m = p; m <= 100000; m += p) {
                    prime_score[m]++;
                }
            }
        }
        
        vector<int> ps(n);
        for (int i = 0; i < n; i++) {
            ps[i] = prime_score[nums[i]];
        }
        
        vector<int> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && ps[st.top()] < ps[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
        vector<int> next_greater(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && ps[st.top()] <= ps[i]) st.pop();
            if (!st.empty()) next_greater[i] = st.top();
            st.push(i);
        }
        
        vector<int> right(n);
        for (int i = 0; i < n; i++) {
            right[i] = (next_greater[i] == n ? n - 1 : next_greater[i] - 1);
        }
        
        vector<long long> count(n);
        for (int i = 0; i < n; i++) {
            count[i] = (long long)(i - left[i] + 1) * (right[i] - i + 1);
        }
        
        vector<long long> total_count(100001, 0);
        for (int i = 0; i < n; i++) {
            total_count[nums[i]] += count[i];
        }
        
        vector<int> vals;
        for (int v = 1; v <= 100000; v++) {
            if (total_count[v] > 0) vals.push_back(v);
        }
        sort(vals.rbegin(), vals.rend()); 
        
        long long score = 1;
        long long remaining_k = k;
        for (int v : vals) {
            if (remaining_k <= 0) break;
            long long use = min(remaining_k, total_count[v]);
            score = score * pow_mod(v, use, MOD) % MOD;
            remaining_k -= use;
        }
        
        return score;
    }
};