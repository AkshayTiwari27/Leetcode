class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        auto isPrime = [&](int n) {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) return false;
            }
            return true;
        };
        
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        
        if (primes.size() < 2) {
            return {-1, -1};
        }
        
        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i], primes[i + 1]};
            }
        }
        
        return result;
    }
};