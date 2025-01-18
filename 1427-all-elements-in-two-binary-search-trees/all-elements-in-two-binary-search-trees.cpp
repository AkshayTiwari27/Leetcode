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
    void inorder(TreeNode* root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    void merge(vector<int>&arr1,vector<int>&arr2,vector<int>&result){
        int i=0,j=0,k=0;
        int n=arr1.size();
        int m=arr2.size();
        while(i<arr1.size()&& j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                result[k++]=arr1[i++];
            }
            else result[k++]=arr2[j++];
        }
        while(i<n){
            result[k++]=arr1[i++];
        }
        while(j<m){
            result[k++]=arr2[j++];
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1,tree2;
        inorder(root1,tree1);
        inorder(root2,tree2);
        vector<int>result(tree1.size()+tree2.size());
        merge(tree1,tree2,result);

        return result;
    }
};