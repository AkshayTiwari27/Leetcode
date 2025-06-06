class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char>minchar(n);
        minchar[n-1] = s[n-1];
        for(int i = n-2; i>= 0; i--){
            minchar[i] = min(s[i], minchar[i+1]);
        }

        string paper;
        string t;
        int i = 0;
        while(i<n){
            t += s[i];
            char mini = i+1<n? minchar[i+1]: s[i];
            while(!t.empty() && t.back() <= mini){
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        while(!t.empty()){
            paper+= t.back();
            t.pop_back();
        }

        return paper;
    }
};