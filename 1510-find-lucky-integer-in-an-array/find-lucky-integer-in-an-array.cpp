class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        int maxi = INT_MIN;
        int maxino = -1;
        for(auto &it : mp){

            if(it.second == it.first){
                if(maxi < it.second){
                    maxi = it.second;
                    maxino = it.first;
                }
                else if(maxi == it.second){
                    maxino = max(maxino, it.first);
                }
            }
            
        }

        return maxino;
    }
};