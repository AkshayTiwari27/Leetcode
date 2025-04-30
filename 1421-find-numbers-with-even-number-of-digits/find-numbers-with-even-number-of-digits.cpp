class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigitCount = 0; 

        for (int num : nums) {
            string s = to_string(num);

            if (s.length() % 2 == 0) {
                evenDigitCount++; 
            }
        }

        return evenDigitCount;
    }
};