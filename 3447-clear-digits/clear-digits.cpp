class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        string result;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());

        return result;
    }
};