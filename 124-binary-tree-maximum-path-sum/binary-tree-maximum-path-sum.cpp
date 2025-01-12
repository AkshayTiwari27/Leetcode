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
    int maxsum=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int both=root->val+l+r;
        int one=root->val+max(l,r);
        int op=root->val;

        maxsum=max({maxsum,both,one,op});
        return max(one,op);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);

        return maxsum;
    }
};