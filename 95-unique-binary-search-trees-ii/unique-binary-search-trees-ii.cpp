/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>, vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {NULL};
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return mp[{start, end}] = {root};
        }

        if(mp.count({start,end})) return mp[{start, end}];

        vector<TreeNode*>result;
        for(int i = start; i<= end; i++){
            vector<TreeNode*>leftBst = solve(start, i-1);
            vector<TreeNode*>rightBst = solve(i+1, end);

            for(auto leftroot: leftBst){
                for(auto rightroot : rightBst){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftroot;
                    root->right = rightroot;
                    result.push_back(root);
                }
            }
        }

        return mp[{start, end}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};