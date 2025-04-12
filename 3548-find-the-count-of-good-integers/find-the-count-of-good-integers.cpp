class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int d = (n+1)/2;
        int start = pow(10, d-1);
        int end = pow(10, d) - 1;

        unordered_set<string>st;
        for(int i = start; i <= end; i++){
            string left = to_string(i);
            string full = "";
            if(n%2 == 0){
                string right = left;
                reverse(right.begin(), right.end());
                full = left + right;
            }
            else{
                string right = left.substr(0, d-1);
                reverse(right.begin(), right.end());
                full = left + right;
            }

            long long num = stoll(full);
            if(num % k != 0) continue;

            sort(full.begin(), full.end());
            st.insert(full);
        }

        vector<int>factorial(11,1);
        for(int i = 1; i<11; i++){
            factorial[i] = i* factorial[i-1];
        }
        long long result = 0;
        for(auto s:st){
            vector<int>freq(10,0);
            for(auto &ch: s){
                freq[ch - '0']++;
            }
            long long total = s.length();
            long long zero = freq[0];
            long long nonzero = total - zero;

            long long perm = nonzero * factorial[total - 1];
            for(int i = 0; i<10; i++){
                perm /= factorial[freq[i]];

            }

            result += perm;
        }

        return result;
    }
};