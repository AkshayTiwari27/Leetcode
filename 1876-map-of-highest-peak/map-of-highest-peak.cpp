class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [i,j]=q.front();
                q.pop();

                for(auto dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 &&j_>=0 && i_<isWater.size() && j_<isWater[0].size() && result[i_][j_]==-1){
                        q.push({i_,j_});
                        result[i_][j_]=result[i][j]+1;
                    }
                }
            }
        }

        return result;
    }
};