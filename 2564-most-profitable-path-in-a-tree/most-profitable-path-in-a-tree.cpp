class Solution {
public:
    int aliceIncome;
    unordered_map<int, vector<int>>adj;
    unordered_map<int, int>mp;
    bool dfsbob(int curr, int time, vector<bool>&visited){
        visited[curr] = true;
        mp[curr] = time;
        if(curr == 0) return true;

        for(auto &v: adj[curr]){
            if(!visited[v]){
                if(dfsbob(v, time + 1, visited)) return true;
            }
        }
        mp.erase(curr);
        return false;
    }

    void dfsAlice(int curr, int time, int income, vector<bool>&visited, vector<int>& amount){
        visited[curr] = true;

        if(mp.find(curr) == mp.end() || time < mp[curr]) income += amount[curr];
        else if(time == mp[curr]) income += amount[curr]/2;

        if(adj[curr].size() == 1 && curr != 0) aliceIncome = max(aliceIncome, income);
        for(auto &v: adj[curr]){
            if(!visited[v]){
                dfsAlice(v, time + 1, income, visited, amount);
            }
        }
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n, false);
        int time = 0;

        dfsbob(bob, time, visited);
        int income = 0;
        visited.assign(n,false);
        dfsAlice(0, 0, income, visited, amount);
        return aliceIncome;

    }
};