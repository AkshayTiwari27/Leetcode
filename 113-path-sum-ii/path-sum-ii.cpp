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
    vector<vector<int>>result;
    void solve(TreeNode* root,int sum,vector<int>temp,int targetSum){
        if(!root) return;
        sum=sum+root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==targetSum){
                result.push_back(temp);
            }
            return;
        }

        solve(root->left,sum,temp,targetSum);
        solve(root->right,sum,temp,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        
        solve(root,sum,temp,targetSum);
        return result;
    }
};