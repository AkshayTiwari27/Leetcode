class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        bool flip=true;
        vector<int>result;
        for(auto &it:mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto &its:it.second){
                result.push_back(its);
            }
            flip=!flip;
        }

        return result;
    }
};