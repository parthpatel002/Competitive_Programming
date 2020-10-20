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
    
    Node* recurse(Node* node, unordered_map<Node*, Node*>& umap){
        Node* node_new = new Node(node->val);
        umap[node] = node_new;
        vector<Node*>* neighbors_new = new vector<Node*>();
        for(Node* n: node->neighbors){
            if (umap.find(n) != umap.end()){
                neighbors_new->push_back(umap[n]);
            }
            else{
                neighbors_new->push_back(recurse(n, umap));
            }
        }
        node_new->neighbors = *neighbors_new;
        return node_new;
    }
    
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        unordered_map<Node*, Node*> umap {};
        return recurse(node, umap);
    }
    
};
