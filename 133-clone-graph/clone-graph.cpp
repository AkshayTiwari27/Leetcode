/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;
    void dfs(Node* node, Node* clone_node){
        for(auto& v:node->neighbors){
            if(mp.find(v) == mp.end()){
                Node* clone = new Node(v->val);
                mp[v] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(v, clone);
            }
            else{
                clone_node->neighbors.push_back(mp[v]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp.clear();
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        dfs(node, clone_node);

        return clone_node;
    }
};