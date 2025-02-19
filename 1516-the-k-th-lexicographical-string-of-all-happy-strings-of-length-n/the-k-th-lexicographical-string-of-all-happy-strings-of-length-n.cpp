class Solution {
public:
    void solve(int n, string& curr, vector<string>&result){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(char s = 'a'; s <= 'c'; s++){
            if(!curr.empty() && curr.back() == s) continue;
            curr.push_back(s);

            solve(n, curr, result);

            curr.pop_back();

        }
    }
    string getHappyString(int n, int k) {
        vector<string>result;
        string curr = "";
        solve(n, curr, result);

        if(result.size() < k) return "";
        return result[k-1];
    }
};