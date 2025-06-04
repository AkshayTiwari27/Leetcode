class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int n=citations.size();
        for(int i=0;i<n;i++){
            if(citations[i]>=i+1) continue;
            else return i;
        }
        return n;
    }
};