class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        int counter = 1;
        stack<char>st;
        int n = pattern.size();

        for(int i = 0; i <= n; i++){
            st.push(counter + '0');
            counter++;

            if(pattern[i] == 'I' || i == n){
                while(!st.empty()){
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;
    }
};