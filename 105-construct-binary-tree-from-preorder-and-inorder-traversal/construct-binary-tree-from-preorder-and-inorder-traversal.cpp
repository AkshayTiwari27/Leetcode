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
    int find(vector<int>& inorder, int start, int end,int target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) return i;
        }

        return -1;
    }
    TreeNode* Tree(vector<int>& preorder, vector<int>& inorder,int start,int end,int index){
        if(start>end) return NULL;
        TreeNode* root= new TreeNode(preorder[index]);
        int pos=find(inorder,start,end,preorder[index]);
        root->left=Tree(preorder,inorder,start,pos-1,index+1);
        root->right=Tree(preorder,inorder,pos+1,end,index+(pos-start)+1);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return Tree(preorder,inorder,0,n-1,0);
    }
};