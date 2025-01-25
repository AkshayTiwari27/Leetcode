class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int groupNum=0;
        unordered_map<int,int>numToGroup;
        numToGroup[v[0]]=groupNum;
        unordered_map<int,list<int>>groupToList;
        groupToList[groupNum].push_back(v[0]);

        int n=nums.size();
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]>limit) groupNum+=1;
            numToGroup[v[i]]=groupNum;
            groupToList[groupNum].push_back(v[i]);
        }

        vector<int>result(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int group=numToGroup[num];
            result[i]=groupToList[group].front();
            groupToList[group].pop_front();
        }

        return result;
    }
};