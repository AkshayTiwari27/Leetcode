class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        result[0][0]=0;

        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int currCost=a[0];
            int i=a[1];
            int j=a[2];

            for(int dir_i=0;dir_i<=3;dir_i++){
                int i_=i+dir[dir_i][0];
                int j_=j+dir[dir_i][1];
                
                if(i_>=0 &&j_>=0 && i_<m && j_<n){
                    int nextCost=currCost+(grid[i][j]-1!=dir_i?1:0);
                    if(nextCost<result[i_][j_]){
                        result[i_][j_]=nextCost;
                        pq.push({nextCost,i_,j_});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};