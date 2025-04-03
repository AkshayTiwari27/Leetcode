class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(int i = 0; i<digits.size(); i++){
            int total_sum = digits[i] + carry;
            int sum = total_sum % 10;
            digits[i] = sum;
            carry = total_sum/10;
        }

        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};