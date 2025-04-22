const int MOD = 1000000007;
const int K_max = 14;
const int MAX_N_COMB = 10001; 
long long fact[MAX_N_COMB];
long long invFact[MAX_N_COMB];
bool combinations_computed_static = false;
int precomputed_max_n_static = -1;

vector<vector<int>> divisors_static;
vector<vector<long long>> h_static;
bool dp_computed_static = false;
int computed_maxValue_static = 0;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    if (n <= 0) return 0; 
    return power(n, MOD - 2);
}

void precomputeCombinationsStatic(int max_n_needed) {
    if (max_n_needed <= precomputed_max_n_static) return;
    int start_n = 0;
    if (precomputed_max_n_static == -1) {
        fact[0] = 1;
        start_n = 1;
    } else {
        start_n = precomputed_max_n_static + 1;
    }

    for (int i = start_n; i <= max_n_needed; ++i) {
        if (i == 0) continue;
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[max_n_needed] = modInverse(fact[max_n_needed]);
    for (int i = max_n_needed - 1; i >= 0; --i) {
        invFact[i] = (invFact[i + 1] * (long long)(i + 1)) % MOD;
    }

    precomputed_max_n_static = max_n_needed;
}

long long nCr_static(int n_val, int r_val) {
    if (r_val < 0 || r_val > n_val) return 0;
    precomputeCombinationsStatic(n_val);
    long long num = fact[n_val];
    long long den1 = invFact[r_val];
    long long den2 = invFact[n_val - r_val];
    return (((num * den1) % MOD) * den2) % MOD;
}

void precomputeDivisorsAndDPStatic(int max_val) {
    if (dp_computed_static && max_val <= computed_maxValue_static) return;
    divisors_static.assign(max_val + 1, vector<int>());
    for (int i = 1; i <= max_val; ++i) {
        for (int j = i; j <= max_val; j += i) {
            divisors_static[j].push_back(i);
        }
    }

    h_static.assign(max_val + 1, vector<long long>(K_max + 1, 0));
    for (int x = 1; x <= max_val; ++x) {
        h_static[x][1] = 1;
    }

    for (int k = 2; k <= K_max; ++k) {
        for (int x = 1; x <= max_val; ++x) {
            for (int y : divisors_static[x]) {
                if (y < x) {
                    h_static[x][k] = (h_static[x][k] + h_static[y][k - 1]) % MOD;
                }
            }
        }
    }

    dp_computed_static = true;
    computed_maxValue_static = max_val;
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        precomputeDivisorsAndDPStatic(maxValue);
        precomputeCombinationsStatic(n - 1);

        long long total_ways = 0;
        for (int k = 1; k <= K_max; ++k) {
            if (n < k) continue;

            long long count_k = 0; 
            for (int x = 1; x <= maxValue; ++x) {
                count_k = (count_k + h_static[x][k]) % MOD;
            }
            if (count_k == 0) continue;

            long long comb = nCr_static(n - 1, k - 1);
            total_ways = (total_ways + (count_k * comb) % MOD) % MOD;
        }

        return (int)total_ways;
    }
};
