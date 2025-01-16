class Solution {
public:
    int xorAllNums(vector<int>& num1, vector<int>& num2) {
        int m=num1.size();
        int n=num2.size();
        unordered_map<int,long>mp;
        for(auto& num:num1){
            mp[num]+=n;
        }
        for(auto&num: num2){
            mp[num]+=m;
        }
        int result=0;
        for(auto it:mp){
            if(it.second%2!=0){
                result^=it.first;
            }
        }

        return result;
    }
};