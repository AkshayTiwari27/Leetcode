class Solution {
private:
    void solve(int depth, int target, vector<vector<int>>& res, vector<int>& output, int st){

        if( target==0 && depth ==0){
            res.push_back(output);
            return;
        }

        if(depth <= 0 || target <= 0) return;

        for(int i=st; i<=target && i<=9; i++ ){

            output.push_back(i);
            solve(depth-1, target-i, res, output, i+1);
            output.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> output;

        if( n < (k*(k+1)/2)) return res;

        solve(k, n, res, output, 1);

        return res;
        
    }
};