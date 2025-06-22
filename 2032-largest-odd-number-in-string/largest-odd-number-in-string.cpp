class Solution {
public:
    string largestOddNumber(string nums) {
        string num = "";
        for(int i = nums.size()-1; i>= 0; i--){
            int nu = nums[i] - '0';
            if(nu & 1){
                num = nums.substr(0, i+1);
                break;
            }
        }

        return num;
    }
};