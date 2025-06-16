class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        queue<Node*>q;
        q.push(root);
        Node* prev;

        while(!q.empty()){
            int N=q.size();
            prev=NULL;
            while(N--){
                Node* curr=q.front();
                q.pop();

                if(prev) prev->next=curr;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                prev=curr;
            }
        }
        return root;
    }
};