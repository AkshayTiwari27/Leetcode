class Solution {
public:
    bool isSubset(vector<int> &temp,vector<int>&freq){
        for(int i=0;i<26;i++){
            if(temp[i]<freq[i]) return false;
        }

        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq2(26,0);
        vector<string>result;
        for(auto word:words2){
            vector<int>temp(26,0);
            for(auto ch:word){
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }
        }

        for(auto word:words1){
            vector<int>temp(26,0);
            for(auto ch:word){
                temp[ch-'a']++;
            }
            if(isSubset(temp,freq2)){
                result.push_back(word);
            }
        }

        return result;
    }
};