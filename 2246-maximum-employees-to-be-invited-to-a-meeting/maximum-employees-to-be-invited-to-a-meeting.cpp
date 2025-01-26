class Solution {
public:
    int bfs(int start,unordered_map<int,vector<int>>adj,vector<bool>&visited){
        int maxDistance=0;
        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start] = true;

        
        while(!q.empty()){
            auto [currNode,dist]=q.front();
            q.pop();
            for(auto& v:adj[currNode]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,dist+1});
                    maxDistance=max(maxDistance,dist+1);
                }
            }
        }


        return maxDistance;
    }
    int maximumInvitations(vector<int>& favourite) {
        int n=favourite.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=i;
            int v=favourite[i];
            adj[v].push_back(u);
        }

        int happyCount=0;
        int maxLength=0;
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                unordered_map<int,int>mp;
                int currNode=i;
                int currCount=0;
                while(!visited[currNode]){
                    visited[currNode]=true;
                    mp[currNode]=currCount;
                    int nextNode=favourite[currNode];
                    currCount+=1;
                    if(mp.count(nextNode)){
                        int length=currCount-mp[nextNode];
                        maxLength=max(maxLength,length);
                        if(length==2){
                            vector<bool>visitedNodes(n,false);
                            visitedNodes[currNode]=true;
                            visitedNodes[nextNode]=true;
                            happyCount+=2+bfs(currNode,adj,visitedNodes)+bfs(nextNode,adj,visitedNodes);
                        }
                        break;
                    }
                    currNode=nextNode;
                }
            }
        }

        return max(happyCount,maxLength);
    }
};