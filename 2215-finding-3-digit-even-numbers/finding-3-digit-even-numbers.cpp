class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>mp(10,0);
        for(auto &digit: digits){
            mp[digit]++;
        }
        vector<int>result;

        for(int i = 1; i<10; i++){
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j = 0; j<=9; j++){
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0; k<=8; k+=2){
                    if(mp[k] == 0) continue;
                    mp[k]--;
                    int num = i*100 + j*10 +k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }

        return result;
    }
};