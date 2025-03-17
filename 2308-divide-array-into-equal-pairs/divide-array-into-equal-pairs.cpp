class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &x: nums){
            if(st.count(x)){
                st.erase(x);
            }else st.insert(x);
        }

        return st.empty();
    }
};