/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void helper1(TreeNode* root,string& temp){
        if(!root) return;
        temp+=to_string(root->val)+'#';
        helper1(root->left,temp);
        helper1(root->right,temp);
    }
    string serialize(TreeNode* root) {
        string temp="";
        helper1(root,temp);
        return temp;
    }

    TreeNode* helper2(TreeNode* root,int value){
        if(!root){
            TreeNode* temp=new TreeNode(value);
            return temp;
        }
        if(value<=root->val) root->left=helper2(root->left,value);
        else root->right=helper2(root->right,value);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        TreeNode* root=NULL;
        while(i<data.length()){
            string temp;
            while(i<data.length()&& data[i]!='#'){
                temp+=data[i++];
            }
            root=helper2(root,stoi(temp));
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;