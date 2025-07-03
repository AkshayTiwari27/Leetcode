class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()< k){
            string temp;
            for(int i = 0; i<word.size(); i++){
                char curr = word[i];
                temp += curr + 1;
            }

            word += temp;
        }

        return word[k-1];
    }
};