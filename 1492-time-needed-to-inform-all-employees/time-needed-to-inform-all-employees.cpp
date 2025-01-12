class Solution {
public:
    int maxtime=0;

    void dfs(unordered_map<int,vector<int>>&adj,vector<int>& informTime,int curr_emp,int curr_time){
        maxtime=max(maxtime,curr_time);
        for(auto& employee:adj[curr_emp]){
            dfs(adj,informTime,employee,curr_time+informTime[curr_emp]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<manager.size();i++){
            int employee=i;
            int manager_i=manager[i];
            if(manager_i!=-1)adj[manager_i].push_back(i);
        }

        dfs(adj,informTime,headID,0);
        return maxtime;
    }
};