class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<long long,vector<long long>, greater<long long>>pq(nums.begin(), nums.end());

        while(pq.size()>1 && pq.top()<k ){
            long long a = pq.top(); 
            pq.pop();
            long long b = pq.top();
            pq.pop();
            count++;
            long long ans = (min(a, b) * 2) + max(a, b);
            pq.push(ans);
        }

        return count;
    }
};