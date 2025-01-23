class Solution {
public:
    long long ans = 0; 
    void helper(TreeNode* root, long long sum) { 
        if (!root) return;
        if (sum == root->val) ans++;
        sum -= root->val; 
        helper(root->left, sum);
        helper(root->right, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        helper(root, (long long)targetSum); 
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};