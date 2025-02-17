class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(), nums.end());
        int score = 0;
        while(k--){
            int a = pq.top();
            pq.pop();
            score += a;
            pq.push(a + 1);
        }

        return score;
    }
};