class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int d : digits)
            freq[d]++;

        int count = 0;
        for(int num = 100; num <= 998; num += 2){
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> tempFreq(10, 0);
            tempFreq[a]++;
            tempFreq[b]++;
            tempFreq[c]++;

            if(tempFreq[a] <= freq[a] && tempFreq[b] <= freq[b] && tempFreq[c] <= freq[c])
                count++;
        }
        return count;
    }
};