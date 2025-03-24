class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int end = 0;
        int result = 0;
        for(int i = 0; i<meetings.size(); i++){
            if(meetings[i][0] > end){
                result += meetings[i][0] - end - 1;
            }
            end = max(end, meetings[i][1]);
        }
        if(end < days) result += days - end;

        return result;
    }
};